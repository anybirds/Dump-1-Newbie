#pragma once

namespace Engine {
	static private ref class Utility {
	public:
		static const char *StringToCharArray(System::String ^str) {
			const char *ret = (const char *)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str)).ToPointer();
			return ret;
		}

		static System::String ^CharArrayToString(const char *str) {
			return gcnew System::String(str);
		}
	};
}