
#include "ZephyrPCH.h"

#include "Mouse.h"

namespace Zephyr
{
	Vec2<int> Mouse::GetPos() const
	{
		return pos;
	}

	int Mouse::GetX() const
	{
		return pos.X;
	}

	int Mouse::GetY() const
	{
		return pos.Y;
	}

	Vec2<float> Mouse::GetWheel() const
	{
		return wheelOffset;
	}

	float Mouse::GetWheelX() const
	{
		return wheelOffset.X;
	}

	float Mouse::GetWheelY() const
	{
		return wheelOffset.Y;
	}

	bool Mouse::LeftIsPressed() const
	{
		return leftPressed;
	}

	bool Mouse::RightIsPressed() const
	{
		return rightPressed;
	}

	bool Mouse::WheelIsPressed() const
	{
		return wheelPressed;
	}

	bool Mouse::InWindow() const
	{
		return inWindow;
	}

	std::shared_ptr<Event> Mouse::ReadClick()
	{
		std::shared_ptr<Event> clickEvent;
		if (!clickBuffer.empty())
		{
			clickEvent = clickBuffer.front();
			clickBuffer.pop();
		}

		return clickEvent;
	}

	std::shared_ptr<Event> Mouse::ReadMove()
	{
		std::shared_ptr<Event> moveEvent = std::shared_ptr<Event>();
		if (!moveBuffer.empty())
		{
			moveEvent = moveBuffer.front();
			moveBuffer.pop();
		}

		return moveEvent;
	}

	std::shared_ptr<Event> Mouse::ReadWheel()
	{
		std::shared_ptr<Event> wheelEvent;
		if (!wheelBuffer.empty())
		{
			wheelEvent = wheelBuffer.front();
			wheelBuffer.pop();
		}

		return wheelEvent;
	}

	bool Mouse::ClickIsEmpty()
	{
		return clickBuffer.empty();
	}

	bool Mouse::MoveIsEmpty()
	{
		return moveBuffer.empty();
	}

	bool Mouse::WheelIsEmpty()
	{
		return wheelBuffer.empty();
	}

	void Mouse::FlushClick()
	{
		clickBuffer = std::queue<std::shared_ptr<Event>>();
	}

	void Mouse::FlushMove()
	{
		moveBuffer = std::queue<std::shared_ptr<Event>>();
	}

	void Mouse::FlushWheel()
	{
		wheelBuffer = std::queue<std::shared_ptr<Event>>();
	}

	void Mouse::Flush()
	{
		FlushClick();
		FlushMove();
		FlushWheel();
	}

	void Mouse::OnMouseMove(Vec2<int> pos)
	{
		this->pos = pos;
		moveBuffer.push(std::make_shared<MouseMove>(pos));
		TrimBuffer(moveBuffer);
	}

	void Mouse::OnMouseEnter()
	{
		inWindow = true;
	}

	void Mouse::OnMouseLeave()
	{
		inWindow = false;
	}

	void Mouse::OnButtonPress(int button)
	{
		clickBuffer.push(std::make_shared<MouseButtonPress>(button));
		TrimBuffer(clickBuffer);
	}

	void Mouse::OnButtonRelease(int button)
	{
		clickBuffer.push(std::make_shared<MouseButtonRelease>(button));
		TrimBuffer(clickBuffer);
	}

	void Mouse::OnScroll(Vec2<float> wheel)
	{
		wheelOffset = wheel;
		wheelBuffer.push(std::make_shared<MouseScroll>(wheel));
		TrimBuffer(wheelBuffer);
	}

	template<typename T>
	void Mouse::TrimBuffer(std::queue<T>& buffer)
	{
		while (buffer.size() > bufferSize)
		{
			buffer.pop();
		}
	}

}