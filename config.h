/* See LICENSE file for copyright and license details. */

/* for XF86 Media Keys */
#include <X11/XF86keysym.h>

/* appearance */
#define grey "#444444"
#define lightGrey "#cccccc"
static const char *fonts[] = {
  "-*-dejavu sans mono-medium-r-normal-*-12-*-*-*-*-*-*"
};
static const char normbordercolor[] = grey;
static const char normbgcolor[]     = grey;
static const char normfgcolor[]     = lightGrey;
static const char selbordercolor[]  = lightGrey;
static const char selbgcolor[]      = lightGrey;
static const char selfgcolor[]      = grey;
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */

/* tagging */
static const char *tags[] = { "1", "2", "3" };

static const Rule rules[] = {
  { "Gimp",     NULL,       NULL,       0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = .5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
  /* symbol     arrange function */
  { "[T]",      tile },    /* first entry is default */
  { "[F]",      NULL },    /* no layout function means floating behavior */
  { "[M]",      monocle },
};

/* key definitions */
#define WIN Mod4Mask
#define ALT Mod1Mask
#define CTRL ControlMask
#define SHIFT ShiftMask
#define TAGKEYS(KEY,TAG) \
{  WIN|SHIFT,  KEY,  view,        {.ui  =  1  <<  TAG}  },  \
{  WIN,        KEY,  tag,         {.ui  =  1  <<  TAG}  },  \
/* {  WIN|CTRL,   KEY,  toggleview,  {.ui  =  1  <<  TAG}  },  \
   { WIN|CTRL|SHIFT, KEY,      toggletag,      {.ui = 1 << TAG} }, */

/* commands */
#define terminalApp "termite", "-e"
static  const  char  *lockcmd[]               =  {  "slock",         NULL           };
static  const  char  *termcmd[]               =  {  "termite",         NULL           };
static  const  char  *webcmd[]                =  {  "firefox",         NULL           };
static  const  char  *editcmd[]               =  {  terminalApp,        "vim",         NULL           };
static  const  char  *monitorcmd[]            =  {  terminalApp,        "htop",        NULL           };
static  const  char  *fileExplorercmd[]       =  {  terminalApp,        "ranger",      NULL           };
static  const  char  *audioMutecmd[]          =  {  "pulseaudio-ctl",  "mute",        NULL           };
static  const  char  *audioInputMutecmd[]     =  {  "pulseaudio-ctl",  "mute-input",  NULL           };
static  const  char  *audioUpcmd[]            =  {  "pulseaudio-ctl",  "up",          NULL           };
static  const  char  *audioDowncmd[]          =  {  "pulseaudio-ctl",  "down",        NULL           };
static  const  char  *brightnessUpcmd[]       =  {  "xbacklight",      "-inc",        "10",          NULL        };
static  const  char  *brightnessDowncmd[]     =  {  "xbacklight",      "-dec",        "10",          NULL        };
static  const  char  *zoomIncmd[]             =  {  "xrandr",          "--output",    "eDP1",        "--scale",  ".7x.7",  NULL  };
static  const  char  *zoomOutcmd[]            =  {  "xrandr",          "--output",    "eDP1",        "--scale",  "1x1",    NULL  };

static Key keys[] = {
  /* modifier                     key        function        argument */
  // Apps
{  WIN,  XK_l,  spawn,  {.v  =  lockcmd          }  },
{  WIN,  XK_t,  spawn,  {.v  =  termcmd          }  },
{  WIN,  XK_w,  spawn,  {.v  =  webcmd           }  },
{  WIN,  XK_e,  spawn,  {.v  =  editcmd          }  },
{  WIN,  XK_h,  spawn,  {.v  =  monitorcmd       }  },
{  WIN,  XK_f,  spawn,  {.v  =  fileExplorercmd  }  },
  // Media Keys
{  0,     XF86XK_AudioMute,          spawn,  {.v  =  audioMutecmd       }  },
{  CTRL,  XF86XK_AudioMute,          spawn,  {.v  =  audioInputMutecmd  }  },
{  0,     XF86XK_AudioRaiseVolume,   spawn,  {.v  =  audioUpcmd         }  },
{  0,     XF86XK_AudioLowerVolume,   spawn,  {.v  =  audioDowncmd       }  },
{  0,     XF86XK_MonBrightnessUp,    spawn,  {.v  =  brightnessUpcmd    }  },
{  0,     XF86XK_MonBrightnessDown,  spawn,  {.v  =  brightnessDowncmd  }  },
{  WIN,   XK_exclam,                 spawn,  {.v  =  zoomIncmd          }  },
{  WIN,   XK_m,                      spawn,  {.v  =  zoomOutcmd         }  },
  // Windows
{  CTRL,       XK_space,      killclient,  {0}  },
{  WIN,        XK_b,          togglebar,   {0}  },
{  WIN,        XK_Up,         setlayout,   {.v  =   &layouts[2]}  },
{  WIN,        XK_Down,       setlayout,   {.v  =   &layouts[0]}  },
{  WIN|SHIFT,  XK_agrave,     resetfacts,  {0}  },
{  WIN|SHIFT,  XK_Left,       setmfact,    {.f  =   -0.05}        },
{  WIN|SHIFT,  XK_Right,      setmfact,    {.f  =   +0.05}        },
{  WIN|SHIFT,  XK_Up,         setcfact,    {.f  =   +0.25}        },
{  WIN|SHIFT,  XK_Down,       setcfact,    {.f  =   -0.25}        },
{  WIN,        XK_Left,       focusstack,  {.i  =   -1            }   },
{  WIN,        XK_Right,      focusstack,  {.i  =   +1            }   },
{  WIN,        XK_i,          incnmaster,  {.i  =   +1            }   },
{  WIN,        XK_d,          incnmaster,  {.i  =   -1            }   },
{  WIN,        XK_Return,     zoom,        {0}  },
{  CTRL|ALT,   XK_Right,      shiftview,   {.i  =   +1}},
{  CTRL|ALT,   XK_Left,       shiftview,   {.i  =   -1            }   },
{  WIN,        XK_comma,      focusmon,    {.i  =   -1            }   },
{  WIN,        XK_semicolon,  focusmon,    {.i  =   +1            }   },
{  WIN|SHIFT,  XK_comma,      tagmon,      {.i  =   -1            }   },
{  WIN|SHIFT,  XK_semicolon,  tagmon,      {.i  =   +1            }   },
{  ALT,        XK_Tab,        lastclient,  {0}  },
  // Tags
  TAGKEYS(  XK_ampersand,   0)
  TAGKEYS(  XK_eacute,      1)
  TAGKEYS(  XK_quotedbl,    2)
  // Misc
{  WIN|SHIFT,  XK_q,  quit,  {0}  },
{  WIN|SHIFT,  XK_r,  restart,  {0}  },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
  /* click                event mask      button          function        argument */
  {  ClkLtSymbol,    0,    Button1,  setlayout,       {0}  },
  {  ClkLtSymbol,    0,    Button3,  setlayout,       {.v  =   &layouts[2]}  },
  {  ClkWinTitle,    0,    Button2,  zoom,            {0}  },
  {  ClkStatusText,  0,    Button2,  spawn,           {.v  =   termcmd       }   },
  {  ClkClientWin,   WIN,  Button1,  movemouse,       {0}  },
  {  ClkClientWin,   WIN,  Button2,  togglefloating,  {0}  },
  {  ClkClientWin,   WIN,  Button3,  resizemouse,     {0}  },
  {  ClkTagBar,      0,    Button1,  view,            {0}  },
  {  ClkTagBar,      0,    Button3,  toggleview,      {0}  },
  {  ClkTagBar,      WIN,  Button1,  tag,             {0}  },
  {  ClkTagBar,      WIN,  Button3,  toggletag,       {0}  },
};

