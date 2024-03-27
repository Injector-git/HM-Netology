#pragma once

#ifdef RACEDLL_EXPORTS
#define RACEDll_API __declspec(dllexport)
#else
#define RACEDll_API __declspec(dllimport)
#endif
