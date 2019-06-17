#define WEBVIEW_IMPLEMENTATION
#include "webview.h"

extern "C" {
void wrapper_webview_free(webview_t* w) ;
void* wrapper_webview_get_userdata(webview_t* w) ;
webview_t wrapper_webview_new(const char* title, const char* url, int width, int height, int resizable, int debug, void* userdata);

}

void wrapper_webview_free(webview_t* w) {
	webview_destroy(w);
}
webview_t wrapper_webview_new(const char* title, const char* url, int width, int height, int resizable, int debug, void* userdata) {

	webview_t w = webview_create(!!debug,nullptr);
	
webview_set_bounds( w, 100,100, width,
                                    height, 1 /* int flags*/ );

	webview_navigate(w,url);
	webview_set_title(w,title);

	// w->width = width;
	// w->height = height;
	// w->title = title;
	// w->url = url;
	// w->resizable = resizable;
	// w->external_invoke_cb = external_invoke_cb;
	// w->userdata = userdata;
	// if (webview_init(w) != 0) {
	// 	wrapper_webview_free(w);
	// 	return NULL;
	// }
	return w;
}

void* wrapper_webview_get_userdata(webview_t* w) {
	//return w->get;
	return {};
}

/*
/JMC /permissive- /GS /analyze- /W3 /Zc:wchar_t /ZI /Gm- /Od /sdl /Fd"Debug\vc142.pdb" /Zc:inline /fp:precise /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /RTC1 /Gd /Oy- /MDd /std:c++17 /FC /Fa"Debug\" /EHsc /nologo /Fo"Debug\" /Fp"Debug\WindowsProject1.pch" /diagnostics:column 
 */


//this works
/*
cl webview.c /std:c++17 /TP /EHsc /Iwebview /DWEBVIEW_EDGE /Fojim.obj
 */