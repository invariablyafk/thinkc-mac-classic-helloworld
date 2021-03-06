#define kBaseResID	      128
#define kMoveToFront      (WindowPtr)-1L
#define kHorizontalPixel  30
#define kVerticalPixel    50

void ToolBoxInit( void );
void WindowInit( void );

void main(){
     ToolBoxInit();
     WindowInit();
     
     while( ! Button() );
     
     SysBeep( 10 ); 
}

void ToolBoxInit(){
     InitGraf( &thePort );
     InitFonts();
     InitWindows();
     InitMenus();
     TEInit();
     InitDialogs( nil );
     InitCursor();
}

void WindowInit(){

     WindowPtr window;
     short fontNum = 0;
     
     window = GetNewWindow( kBaseResID, nil, kMoveToFront );
     
     if(window == nil){
          SysBeep( 10 );
          ExitToShell();
     }

     ShowWindow( window );
     SetPort( window );
     
     GetFNum("\pMonaco", &fontNum);
     
     if(fontNum != 0){
       //   TextFont( fontNum );
     }
     
     MoveTo( kHorizontalPixel, kVerticalPixel );
     DrawString("\pHello, World!");
}

