#pragma once

#include <queue>

#include "Core.h"
#include "Events/MouseEvent.h"

namespace Zephyr
{
	class ZEPHYR_API Mouse
	{
		//friend class MainWindow
	public:
		Mouse() = default;
		Mouse(const Mouse&) = delete;
		Mouse& operator=(const Mouse&) = delete;

		Vec2<int> GetPos() const;
		int GetX() const;
		int GetY() const;
		Vec2<float> GetWheel() const;
		float GetWheelX() const;
		float GetWheelY() const;
		bool LeftIsPressed() const;
		bool RightIsPressed() const;
		bool WheelIsPressed() const;
		bool InWindow() const;

		std::shared_ptr<Event> ReadClick();
		std::shared_ptr<Event> ReadMove();
		std::shared_ptr<Event> ReadWheel();
		bool ClickIsEmpty();
		bool MoveIsEmpty();
		bool WheelIsEmpty();

		void FlushClick();
		void FlushMove();
		void FlushWheel();
		void Flush();

	private:
		void OnMouseMove(Vec2<int> pos);
		void OnMouseEnter();
		void OnMouseLeave();
		void OnButtonPress(int button);
		void OnButtonRelease(int button);
		void OnScroll(Vec2<float> wheel);

		template<typename T>
		void TrimBuffer(std::queue<T>& buffer);

		static constexpr unsigned int bufferSize = 4u;
		Vec2<int> pos;
		Vec2<float> wheelOffset;
		bool leftPressed = false;
		bool rightPressed = false;
		bool wheelPressed = false;
		bool inWindow = false;
		std::queue<std::shared_ptr<Event>> clickBuffer;
		std::queue<std::shared_ptr<Event>> moveBuffer;
		std::queue<std::shared_ptr<Event>> wheelBuffer;
	};
}
