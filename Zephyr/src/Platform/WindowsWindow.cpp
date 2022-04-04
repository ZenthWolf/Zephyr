#include "ZephyrPCH.h"

#include "glad/glad.h"

#include "Zephyr/Events/ApplicationEvent.h"
#include "Zephyr/Events/KeyEvent.h"
#include "Zephyr/Events/MouseEvent.h"
#include "WindowsWindow.h"

namespace Zephyr {

	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description)
	{
		ZW_ENGINE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

	Window* Window::Create(const WindowProperty& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProperty& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProperty& props)
	{
		data.Title = props.Title;
		data.Width = props.Width;
		data.Height = props.Height;

		ZW_ENGINE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			// TODO: glfwTerminate on system shutdown
			int success = glfwInit();
			ZW_ENGINE_ASSERT(success, "Could not intialize GLFW.");
			glfwSetErrorCallback(GLFWErrorCallback);

			s_GLFWInitialized = true;
		}

		//Initialize GLFW, create OpenGL context
		window = glfwCreateWindow((int)props.Width, (int)props.Height, data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(window);
		
		//Initialize Glad- get access to modern OpenGL
		//Target glfw process address
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ZW_ENGINE_ASSERT(status, "Failed to Initialize Glad.");

		glfwSetWindowUserPointer(window, &data);
		SetVSync(true);

		//Set GLFW callbacks
		glfwSetWindowSizeCallback(window, [](GLFWwindow* windowGL, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(windowGL);

			WindowResize event(Vec2<unsigned int>(width, height));
			data.Width = width;
			data.Height = height;
			data.EventCallback(event);
		});

		glfwSetWindowCloseCallback(window, [](GLFWwindow* windowGL)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(windowGL);
			WindowClose event;
			data.EventCallback(event);
		});

		glfwSetKeyCallback(window, [](GLFWwindow* windowGL, int key, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(windowGL);

			switch (action)
			{
			case GLFW_PRESS:
			{
				KeyPress event(key, 0);
				data.EventCallback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				KeyRelease event(key);
				data.EventCallback(event);
				break;
			}
			case GLFW_REPEAT:
			{
				KeyPress event(key, 1); // GLFW does not yield a count
				data.EventCallback(event);
				break;
			}
			}
		});

		glfwSetMouseButtonCallback(window, [](GLFWwindow* windowGL, int button, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(windowGL);

			switch (action)
			{
			case GLFW_PRESS:
			{
				MouseButtonPress event(button);
				data.EventCallback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				MouseButtonRelease event(button);
				data.EventCallback(event);
				break;
			}
			}
		});

		glfwSetScrollCallback(window, [](GLFWwindow* windowGL, double xPos, double yPos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(windowGL);

			MouseScroll event(Vec2<float>((float)xPos, (float)yPos));
			data.EventCallback(event);
		});

		glfwSetCursorPosCallback(window, [](GLFWwindow* windowGL, double xOffset, double yOffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(windowGL);

			MouseMove event(Vec2<float>((float)xOffset, (float)yOffset));
			data.EventCallback(event);
		});
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return data.VSync;
	}

}