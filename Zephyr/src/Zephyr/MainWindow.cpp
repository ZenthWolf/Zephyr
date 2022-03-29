
#include "MainWindow.h"


namespace Zephyr
{
	Vec2<unsigned int> MainWindow::GetWindowSize() const
	{
		return windowSize;
	}

	std::shared_ptr<Event> MainWindow::ReadEvent()
	{
		std::shared_ptr<Event> appevent;
		if (!buffer.empty())
		{
			appevent = buffer.front();
			buffer.pop();
		}

		return appevent;
	}

	void MainWindow::Flush()
	{
		buffer = std::queue<std::shared_ptr<Event>>();
	}

	void MainWindow::OnWindowClose()
	{
		buffer.push(std::make_unique<WindowClose>());
		TrimBuffer();
	}

	void MainWindow::OnWindowResize(Vec2<unsigned int> newSize)
	{
		windowSize = newSize;
		buffer.push(std::make_unique<WindowResize>(newSize));
		TrimBuffer();
	}

	void MainWindow::OnAppTick()
	{
		buffer.push(std::make_unique<AppTick>());
		TrimBuffer();
	}

	void MainWindow::OnAppUpdate()
	{
		buffer.push(std::make_unique<AppUpdate>());
		TrimBuffer();
	}

	void MainWindow::OnAppRender()
	{
		buffer.push(std::make_unique<AppRender>());
		TrimBuffer();
	}

	void MainWindow::TrimBuffer()
	{
		while (buffer.size() > bufferSize)
			buffer.pop();
	}

}
