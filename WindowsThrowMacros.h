#pragma once

#define MEIGA_EXCEPT(hr) Window::HrException(__LINE__,__FILE__, (hr))
#define MEIGA_LAST_EXCEPT() Window::HrException(__LINE__,__FILE__, GetLastError())
#define MEIGA_NOGFX_EXCEPT() Window::NoGfxException( __LINE__,__FILE__ )