#pragma once
//dont forget to link Winmm.lib d2d1.lib dwrite.lib Windowscodecs.lib

struct SKR_Color {
	float r;
	float g;
	float b;
	float a;
};

struct SKR_Rect {
	float x;
	float y;
	float w;
	float h;
};

struct SKR_Texture;

struct SKR_WinRect;

struct SKR_WinGameImage;

struct SKR_WinGameText;

struct SKR_WinBar;

struct SKR_WinButton;

struct SKR_WinMenuImage;

struct SKR_WinMenuText;

int main(void);//you will fill this function 

void SKR_WinInit(float VirtualWidth, float VirtualHeight, unsigned long MaxFps, const char* CursorFile, const char* IconFile);//.cur file path for cursor file parameter, null or 0 for deafult cursor 

void SKR_WinQuit(void);

bool SKR_isWinQuitRequested(void);

float SKR_WinMouseX(void);

float SKR_WinMouseY(void);

bool SKR_WinKeyDown(unsigned char VirtualKeyCode);//virtual key codes: https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes

bool SKR_WinKeyPressed(unsigned char VirtualKeyCode);

void SKR_WinRenderAll(void);

void SKR_DestroyAll(void);

void SKR_FadeIn(SKR_Color* color, float speed, const wchar_t* string, const wchar_t* font, float size, SKR_Rect* textrect, SKR_Color* textcolor);

void SKR_FadeOut(SKR_Color* color, float speed, const wchar_t* string, const wchar_t* font, float size, SKR_Rect* textrect, SKR_Color* textcolor);

void SKR_FocusCamera(SKR_Rect* focusedrect, float minx, float maxx, float miny, float maxy);

SKR_WinRect* SKR_CreateWinRect(SKR_Rect* position, SKR_Color* color, float width, float radiusx, float radiusy, bool* condition);//position pointer will be in the structure but color pointer is just for assigning value

void SKR_DestroyWinRect(SKR_WinRect* winrect);

void SKR_SetRectWidth(SKR_WinRect* winrect, float width);

void SKR_DestroyAllWinRects(void);

SKR_WinBar* SKR_CreateWinBar(SKR_Rect* position, SKR_Color* bordercolor, SKR_Color* backcolor, SKR_Color* frontcolor, float* maxvalue, float* currentvalue, bool* condition, bool direction);//position and color pointers are just assigning values//if direction is 0, bar will be horizontal. Otherwise it is vertical.

void SKR_DestroyWinBar(SKR_WinBar* winbar);

void SKR_DestroyAllWinBars(void);

SKR_WinGameText* SKR_CreateWinGameText(SKR_Rect* position, SKR_Color* color, const wchar_t* string, const wchar_t* font, float size, bool* condition);//system fonts: https://docs.microsoft.com/en-us/typography/fonts/windows_10_font_list

void SKR_DestroyWinGameText(SKR_WinGameText* wingametext);

void SKR_DestroyAllWinGameTexts(void);

SKR_WinMenuText* SKR_CreateWinMenuText(SKR_Rect* position, SKR_Color* color, const wchar_t* string, const wchar_t* font, float size, bool* condition);

void SKR_DestroyWinMenuText(SKR_WinMenuText* winmenutext);

void SKR_DestroyAllWinMenuTexts(void);

SKR_WinButton* SKR_CreateWinButton(SKR_Rect* position, SKR_Color* bordercolor, SKR_Color* backcolor, SKR_Color* frontcolor, SKR_Color* textcolor, const wchar_t* string, const wchar_t* font, float size, bool* clicked, bool* condition, bool oneshot);

void SKR_DestroyWinButton(SKR_WinButton* winbutton);

void SKR_DestroyAllWinButtons(void);

SKR_WinGameImage* SKR_CreateWinGameImage(SKR_Rect* dest, SKR_Rect* src, const wchar_t* file, unsigned char flip, bool* condition, float opacity, int animation, unsigned int milliseconds);//flip 0 no flip, 1 horizontal, 2 vertical
//animation variable must be -1 if you dont want animation and milliseconds variable is not important
//if you want animation, the animation variable must be numbered from largest to smallest. exp: 3 2 1 0 ->a 4 framed animation, you can set how much time will pass on each frame by milliseconds variable

void SKR_DestroyWinGameImage(SKR_WinGameImage* image);

void SKR_DestroyAllWinGameImages(void);

SKR_WinMenuImage* SKR_CreateWinMenuImage(SKR_Rect* dest, SKR_Rect* src, const wchar_t* file, unsigned char flip, bool* condition, float opacity, int animation, unsigned int milliseconds);

void SKR_DestroyWinMenuImage(SKR_WinMenuImage* image);

void SKR_DestroyAllWinMenuImages(void);

SKR_WinGameImage* SKR_CreateCopyWinGameImage(SKR_WinGameImage* image, SKR_Rect* dest, bool* condition, float opacity, int animation, unsigned int milliseconds);

SKR_WinMenuImage* SKR_CreateCopyWinMenuImage(SKR_WinMenuImage* image, SKR_Rect* dest, bool* condition, float opacity, int animation, unsigned int milliseconds);

void SKR_ShowCursor(bool show);

float SKR_GetResMultiplierX(void);

float SKR_GetResMultiplierY(void);

SKR_Texture* SKR_CreateTexture(SKR_Rect* src, const wchar_t* file, unsigned char flip);

SKR_WinGameImage* SKR_CreateWinGameImagebyTexture(SKR_Texture* texture, SKR_Rect* dest, bool* condition, float opacity, int animation, unsigned int milliseconds);

SKR_WinMenuImage* SKR_CreateWinMenuImagebyTexture(SKR_Texture* texture, SKR_Rect* dest, bool* condition, float opacity, int animation, unsigned int milliseconds);

void SKR_DestroyTexture(SKR_Texture* texture);//destroying textures is in your responsibility, they wont be destroyed by SKR_DestroyAll