/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Copyright (c) 1998 Microsoft Corporation

Module Name:

    hiragana.cxx

Abstract:

    This file initializes an array of keys in the hiragana layout.

Environment:

    Runs on Dreamcast under Windows CE.

-------------------------------------------------------------------*/
				

#include "precomp.hpp"


// This array defines the layout for the Hiragana software keyboard.
// Keys must be listed in sorted order by location on keyboard, 
// left to right, and then top to bottom.  The binary search 
// is dependent on this sort order.

// Virtual Key codes are filled in, but many are not used; instead, we just send
// the unicode for the character in a WM_CHAR message.

SOFTKEY g_rgskHiragana[] = 
    {
//       X   Y Wid Hgt              characters on key
//       ----------------------------------------------------------------------------------
        {0,  0,  1,  1,				{HIRAGANA_WA,                   },	},
        {1,  0,  1,  1,				{HIRAGANA_RA,                   },	},
        {2,  0,  1,  1,				{HIRAGANA_YA,                   },	},
        {3,  0,  1,  1,				{HIRAGANA_MA,                   },	},
        {4,  0,  1,  1,				{HIRAGANA_HA,                   },	},
        {5,  0,  2,  1,				{KANJI_CONFIRM_0, KANJI_CONFIRM_1,}, VK_NOCONVERT},
        {7,  0,  1,  1,				{HIRAGANA_NA,                   },	},
        {8,  0,  1,  1,				{HIRAGANA_TA,                   },	},
        {9,  0,  1,  1,				{HIRAGANA_SA,                   },	},
        {10, 0,  1,  1,				{HIRAGANA_KA,                   },	},
        {11, 0,  1,  1,				{HIRAGANA_A,                    },	},
        {12, 0,  1,  1,				{SYMBOLS_EXCLAMATION,           },	},
        {13, 0,  1,  1,				{SYMBOLS_QUESTION,              },	}, 
        {14, 0,  1,  1,				{ROMAN_PLUS,                    },	},
        {15, 0,  1,  1,				{ROMAN_ONE,                     },	},
        {16, 0,  1,  1,				{ROMAN_TWO,                     },	}, 
        {17, 0,  1,  1,				{ROMAN_THREE,                   },	},     
        {0,  1,  1,  1,				{HIRAGANA_WO,                   },	},
        {1,  1,  1,  1,				{HIRAGANA_RI,                   },	},
        {2,  1,  1,  1,				{HIRAGANA_YU,                   },	},
        {3,  1,  1,  1,				{HIRAGANA_MI,                   },	},
        {4,  1,  1,  1,				{HIRAGANA_HI,                   },	},
        {5,  1,  2,  1,				{KANJI_CONVERT_0, KANJI_CONVERT_1,},  VK_CONVERT	},
        {7,  1,  1,  1,				{HIRAGANA_NI,                   },	},
        {8,  1,  1,  1,				{HIRAGANA_CHI,                  },	},
        {9,  1,  1,  1,				{HIRAGANA_SHI,                  },	},
        {10, 1,  1,  1,				{HIRAGANA_KI,                   },	},
        {11, 1,  1,  1,				{HIRAGANA_I,                    },	},
        {12, 1,  1,  1,				{SYMBOLS_LOWLINE,               },	},
        {13, 1,  1,  1,				{SYMBOLS_JAPANESE_DASH,         },	}, 
        {14, 1,  1,  1,				{ROMAN_MINUS,                   },	},
        {15, 1,  1,  1,				{ROMAN_FOUR,                    },	},
        {16, 1,  1,  1,				{ROMAN_FIVE,                    },	}, 
        {17, 1,  1,  1,				{ROMAN_SIX,                     },	},     
        {0,  2,  1,  1,				{HIRAGANA_NN,                   },	},
        {1,  2,  1,  1,				{HIRAGANA_RU,                   },	},
        {2,  2,  1,  1,				{HIRAGANA_YO,                   },	},
        {3,  2,  1,  1,				{HIRAGANA_MU,                   },	},
        {4,  2,  1,  1,				{HIRAGANA_HU,                   },	},
        {5,  2,  2,  1,				{KANJI_SMALL_0,  KANJI_SMALL_1,},	},
        {7,  2,  1,  1,				{HIRAGANA_NU,                   },	},
        {8,  2,  1,  1,				{HIRAGANA_TSU,                  },	},
        {9,  2,  1,  1,				{HIRAGANA_SU,                   },	},
        {10, 2,  1,  1,				{HIRAGANA_KU,                   },	},
        {11, 2,  1,  1,				{HIRAGANA_U,                    },	},
        {12, 2,  1,  1,				{SYMBOLS_PERCENT,               },	},
        {13, 2,  1,  1,				{SYMBOLS_AMPERSAND,             },	}, 
        {14, 2,  1,  1,				{ROMAN_SOLIDUS,                 },	},
        {15, 2,  1,  1,				{ROMAN_SEVEN,                   },	},
        {16, 2,  1,  1,				{ROMAN_EIGHT,                   },	}, 
        {17, 2,  1,  1,				{ROMAN_NINE,                    },	},     
        {0,  3,  1,  1,				{SYMBOLS_IDEO_PERIOD,           },	},
        {1,  3,  1,  1,				{HIRAGANA_RE,                   },	},
        {2,  3,  1,  1,				{SYMBOLS_ROMAN_LEFT_PAREN,      },	},
        {3,  3,  1,  1,				{HIRAGANA_ME,                   },	},
        {4,  3,  1,  1,				{HIRAGANA_HE,                   },	},
        {5,  3,  2,  1,				{KANJI_DELETE_0,  KANJI_DELETE_1,},	VK_BACK},
        {7,  3,  1,  1,				{HIRAGANA_NE,                   },	},
        {8,  3,  1,  1,				{HIRAGANA_TE,                   },	},
        {9,  3,  1,  1,				{HIRAGANA_SE,                   },	},
        {10, 3,  1,  1,				{HIRAGANA_KE,                   },	},
        {11, 3,  1,  1,				{HIRAGANA_E,                    },	},
        {12, 3,  1,  1,				{SYMBOLS_JAPANESE_LEFT_PAREN,   },	},
        {13, 3,  1,  1,				{SYMBOLS_JAPANESE_RIGHT_PAREN,  },	}, 
        {14, 3,  1,  1,				{ROMAN_EQUALS,                  },	},
        {15, 3,  1,  1,				{ROMAN_ASTERISK,                },	},
        {16, 3,  1,  1,				{ROMAN_ZERO,                    },	}, 
        {17, 3,  1,  1,				{ROMAN_TILDE,                   },	}, 
        {0,  4,  1,  1,				{SYMBOLS_IDEO_COMMA,            },	},
        {1,  4,  1,  1,				{HIRAGANA_RO,                   },	},
        {2,  4,  1,  1,				{SYMBOLS_ROMAN_RIGHT_PAREN,     },	},
        {3,  4,  1,  1,				{HIRAGANA_MO,                   },	},
        {4,  4,  1,  1,				{HIRAGANA_HO,                   },	},
        {5,  4,  1,  1,				{SYMBOLS_DAKUTEN,               },	},
        {6,  4,  1,  1,				{SYMBOLS_HANDAKUTEN,            },	},
        {7,  4,  1,  1,				{HIRAGANA_NO,                   },	},
        {8,  4,  1,  1,				{HIRAGANA_TO,                   },	},
        {9,  4,  1,  1,				{HIRAGANA_SO,                   },	},
        {10, 4,  1,  1,				{HIRAGANA_KO,                   },	},
        {11, 4,  1,  1,				{HIRAGANA_O,                    },	},
        {12, 4,  2,  1, 			{KANJI_SYMBOLS_0, KANJI_SYMBOLS_1,},	},
        {14, 4,  1,  1,				{ROMAN_COLON,                   },	},
        {15, 4,  1,  1,				{SYMBOLS_YEN,                   },	},
        {16, 4,  1,  1,				{ROMAN_DECIMAL,                 },	},
        {17, 4,  1,  1,				{ROMAN_NUMBER,                  },	},
        {0,  5,  1,  1,				{HIRAGANA_SWITCH,               },	},
        {4,  5,  3,  1,				{KANJI_SPACE_0,   KANJI_SPACE_1,},	VK_SPACE},
        {7,  5,  5,  1,				{KANJI_CLOSE_0,   KANJI_CLOSE_1, KANJI_CLOSE_2, KANJI_CLOSE_3, KANJI_CLOSE_4, KANJI_CLOSE_5,},	VK_ESCAPE},
        {12, 5,  2,  1,				{KANJI_ENGLISH_0, KANJI_ENGLISH_1,},	},
        {14, 5,  1,  1,				{SYMBOLS_LEFT,                  },	VK_LEFT}, 
        {15, 5,  1,  1,				{SYMBOLS_UP,                    },	VK_UP}, 
        {16, 5,  1,  1,				{SYMBOLS_RIGHT,                 },	VK_RIGHT}, 
        {17, 5,  1,  1,				{SYMBOLS_DOWN,                  },	VK_DOWN}, 
    };

WORD g_cHiraganaKeys = sizeof(g_rgskHiragana) / sizeof(SOFTKEY);  // number of keys on hiragana keyboard

// map from syllable -> hiragana -> dakuten -> handakuten; value is 0 if the character doesn't exist
HIRAGANA_MAP g_rgHiraganaMap[] =
    {
// Hiragana UNICODE        Half-Height      Dakuten         Handakuten
// -------------------------------------------------------------------
/* HIRAGANA_A_HH       */ {0,               0,              0},
/* HIRAGANA_A          */ {HIRAGANA_A_HH,   0,              0},  
/* HIRAGANA_I_HH       */ {0,               0,              0},    
/* HIRAGANA_I          */ {HIRAGANA_I_HH,   0,              0},  
/* HIRAGANA_U_HH       */ {0,               0,              0},    
/* HIRAGANA_U          */ {HIRAGANA_U_HH,   0,              0},  
/* HIRAGANA_E_HH       */ {0,               0,              0},    
/* HIRAGANA_E          */ {HIRAGANA_E_HH,   0,              0},  
/* HIRAGANA_O_HH       */ {0,               0,              0},    
/* HIRAGANA_O          */ {HIRAGANA_O_HH,   0,              0},
/* HIRAGANA_KA         */ {0,               HIRAGANA_KA_DK, 0},
/* HIRAGANA_KA_DK      */ {0,               0,              0},
/* HIRAGANA_KI         */ {0,               HIRAGANA_KI_DK, 0},
/* HIRAGANA_KI_DK      */ {0,               0,              0},
/* HIRAGANA_KU         */ {0,               HIRAGANA_KU_DK, 0},
/* HIRAGANA_KU_DK      */ {0,               0,              0},
/* HIRAGANA_KE         */ {0,               HIRAGANA_KE_DK, 0},
/* HIRAGANA_KE_DK      */ {0,               0,              0},
/* HIRAGANA_KO         */ {0,               HIRAGANA_KO_DK, 0},
/* HIRAGANA_KO_DK      */ {0,               0,              0},
/* HIRAGANA_SA         */ {0,               HIRAGANA_SA_DK, 0},
/* HIRAGANA_SA_DK      */ {0,               0,              0},
/* HIRAGANA_SHI        */ {0,               HIRAGANA_SHI_DK,0},
/* HIRAGANA_SHI_DK     */ {0,               0,              0},
/* HIRAGANA_SU         */ {0,               HIRAGANA_SU_DK, 0},
/* HIRAGANA_SU_DK      */ {0,               0,              0},
/* HIRAGANA_SE         */ {0,               HIRAGANA_SE_DK, 0},
/* HIRAGANA_SE_DK      */ {0,               0,              0},
/* HIRAGANA_SO         */ {0,               HIRAGANA_SO_DK, 0},
/* HIRAGANA_SO_DK      */ {0,               0,              0},
/* HIRAGANA_TA         */ {0,               HIRAGANA_TA_DK, 0},
/* HIRAGANA_TA_DK      */ {0,               0,              0},
/* HIRAGANA_CHI        */ {0,               HIRAGANA_CHI_DK,0},
/* HIRAGANA_CHI_DK     */ {0,               0,              0},
/* HIRAGANA_TSU_HH     */ {0,               0,              0},
/* HIRAGANA_TSU        */ {HIRAGANA_TSU_HH, HIRAGANA_TSU_DK,0},
/* HIRAGANA_TSU_DK     */ {0,               0,              0},
/* HIRAGANA_TE         */ {0,               HIRAGANA_TE_DK, 0},
/* HIRAGANA_TE_DK      */ {0,               0,              0},
/* HIRAGANA_TO         */ {0,               HIRAGANA_TO_DK, 0},
/* HIRAGANA_TO_DK      */ {0,               0,              0},
/* HIRAGANA_NA         */ {0,               0,              0},
/* HIRAGANA_NI         */ {0,               0,              0},
/* HIRAGANA_NU         */ {0,               0,              0},
/* HIRAGANA_NE         */ {0,               0,              0},
/* HIRAGANA_NO         */ {0,               0,              0},
/* HIRAGANA_HA         */ {0,               HIRAGANA_HA_DK, HIRAGANA_HA_HK},
/* HIRAGANA_HA_DK      */ {0,               0,              0},
/* HIRAGANA_HA_HK      */ {0,               0,              0},
/* HIRAGANA_HI         */ {0,               HIRAGANA_HI_DK, HIRAGANA_HI_HK},
/* HIRAGANA_HI_DK      */ {0,               0,              0},
/* HIRAGANA_HI_HK      */ {0,               0,              0},
/* HIRAGANA_HU         */ {0,               HIRAGANA_HU_DK, HIRAGANA_HU_HK},
/* HIRAGANA_HU_DK      */ {0,               0,              0},
/* HIRAGANA_HU_HK      */ {0,               0,              0},
/* HIRAGANA_HE         */ {0,               HIRAGANA_HE_DK, HIRAGANA_HE_HK},
/* HIRAGANA_HE_DK      */ {0,               0,              0},
/* HIRAGANA_HE_HK      */ {0,               0,              0},
/* HIRAGANA_HO         */ {0,               HIRAGANA_HO_DK, HIRAGANA_HO_HK},
/* HIRAGANA_HO_DK      */ {0,               0,              0},
/* HIRAGANA_HO_HK      */ {0,               0,              0},
/* HIRAGANA_MA         */ {0,               0,              0},
/* HIRAGANA_MI         */ {0,               0,              0},
/* HIRAGANA_MU         */ {0,               0,              0},
/* HIRAGANA_ME         */ {0,               0,              0},
/* HIRAGANA_MO         */ {0,               0,              0},
/* HIRAGANA_YA_HH      */ {0,               0,              0},
/* HIRAGANA_YA         */ {HIRAGANA_YA_HH,  0,              0},
/* HIRAGANA_YU_HH      */ {0,               0,              0},
/* HIRAGANA_YU         */ {HIRAGANA_YU_HH,  0,              0},
/* HIRAGANA_YO_HH      */ {0,               0,              0},
/* HIRAGANA_YO         */ {HIRAGANA_YO_HH,  0,              0},
/* HIRAGANA_RA         */ {0,               0,              0},
/* HIRAGANA_RI         */ {0,               0,              0},
/* HIRAGANA_RU         */ {0,               0,              0},
/* HIRAGANA_RE         */ {0,               0,              0},
/* HIRAGANA_RO         */ {0,               0,              0},
/* HIRAGANA_WA_HH      */ {0,               0,              0},
/* HIRAGANA_WA         */ {HIRAGANA_WA_HH,  0,              0},
/* HIRAGANA_UNKNOWN1   */ {0,               0,              0},
/* HIRAGANA_UNKNOWN2   */ {0,               0,              0},
/* HIRAGANA_WO         */ {0,               0,              0},
/* HIRAGANA_NN         */ {0,               0,              0},

/*
        {HIRAGANA_A,            (HIRAGANA_A - 1),       0,                  0                   },      
        {HIRAGANA_I,            (HIRAGANA_I - 1),       0,                  0                   },
        {HIRAGANA_U,            (HIRAGANA_U - 1),       0,                  0                   },
        {HIRAGANA_E,            (HIRAGANA_E - 1),       0,                  0                   },
        {HIRAGANA_O,            (HIRAGANA_O - 1),       0,                  0                   },
        {HIRAGANA_KA,           0,                      (HIRAGANA_KA + 1),  0                   },
        {HIRAGANA_KI,           0,                      (HIRAGANA_KI + 1),  0                   },
        {HIRAGANA_KU,           0,                      (HIRAGANA_KU + 1),  0                   },
        {HIRAGANA_KE,           0,                      (HIRAGANA_KE + 1),  0                   },
        {HIRAGANA_KO,           0,                      (HIRAGANA_KO + 1),  0                   },
        {HIRAGANA_SA,           0,                      (HIRAGANA_SA + 1),  0                   },
        {HIRAGANA_SHI,          0,                      (HIRAGANA_SHI + 1), 0                   },
        {HIRAGANA_SU,           0,                      (HIRAGANA_SU + 1),  0                   },
        {HIRAGANA_SE,           0,                      (HIRAGANA_SE + 1),  0                   },
        {HIRAGANA_SO,           0,                      (HIRAGANA_SO + 1),  0                   },
        {HIRAGANA_TA,           0,                      (HIRAGANA_TA + 1),  0                   },
        {HIRAGANA_CHI,          0,                      (HIRAGANA_CHI + 1), 0                   },
        {HIRAGANA_TSU,          (HIRAGANA_TSU - 1),     (HIRAGANA_TSU + 1), 0                   },
        {HIRAGANA_TE,           0,                      (HIRAGANA_TE + 1),  0                   },
        {HIRAGANA_TO,           0,                      (HIRAGANA_TO + 1),  0                   },
        {HIRAGANA_NA,           0,                      0,                  0                   },
        {HIRAGANA_NI,           0,                      0,                  0                   },
        {HIRAGANA_NU,           0,                      0,                  0                   },
        {HIRAGANA_NE,           0,                      0,                  0                   },
        {HIRAGANA_NO,           0,                      0,                  0                   },
        {HIRAGANA_HA,           0,                      (HIRAGANA_HA + 1),  (HIRAGANA_HA + 2)   },
        {HIRAGANA_HI,           0,                      (HIRAGANA_HI + 1),  (HIRAGANA_HI + 2)   },
        {HIRAGANA_HU,           0,                      (HIRAGANA_HU + 1),  (HIRAGANA_HU + 2)   },
        {HIRAGANA_HE,           0,                      (HIRAGANA_HE + 1),  (HIRAGANA_HE + 2)   },
        {HIRAGANA_HO,           0,                      (HIRAGANA_HO + 1),  (HIRAGANA_HO + 2)   },
        {HIRAGANA_MA,           0,                      0,                  0                   },
        {HIRAGANA_MI,           0,                      0,                  0                   },
        {HIRAGANA_MU,           0,                      0,                  0                   },
        {HIRAGANA_ME,           0,                      0,                  0                   },
        {HIRAGANA_MO,           0,                      0,                  0                   },
        {HIRAGANA_YA,           (HIRAGANA_YA - 1),      0,                  0                   },
        {HIRAGANA_YU,           (HIRAGANA_YU - 1),      0,                  0                   },
        {HIRAGANA_YO,           (HIRAGANA_YO - 1),      0,                  0                   },
        {HIRAGANA_RA,           0,                      0,                  0                   },
        {HIRAGANA_RI,           0,                      0,                  0                   },
        {HIRAGANA_RU,           0,                      0,                  0                   },
        {HIRAGANA_RE,           0,                      0,                  0                   },
        {HIRAGANA_RO,           0,                      0,                  0                   },
        {HIRAGANA_WA,           (HIRAGANA_WA - 1),      0,                  0                   },
        {HIRAGANA_WO,           (HIRAGANA_WO - 1),      0,                  0                   },
        {HIRAGANA_NN,           0,                      0,                  0                   }
*/
    };
