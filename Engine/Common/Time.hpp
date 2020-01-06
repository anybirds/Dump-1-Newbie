#pragma once

namespace Engine {
	public ref class Time {
	private:
		static float m_dt;
		static float m_prev;
		static Time();

	private:
		/*disallow creating instances of this class*/
		Time();

	public:
		/*disallow calling this from Custom*/
		static void Tick();

		static property float deltaTime {
			float get() {
				return m_dt;
			}
		}
	};
}