/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Copyright (c) 1998 Microsoft Corporation

Module Name:

    katakana.cxx

Abstract:

    This file initializes an array of keys in the katakana layout.

Environment:

    Runs on Dreamcast under Windows CE.

-------------------------------------------------------------------*/


#include "precomp.hxx"

#ifdef KANJI
				
// This array defines the layout for the Katakana software keyboard.
// Keys must be listed in sorted order by location on keyboard, 
// left to right, and then top to bottom.  The binary search 
// is dependent on this sort order.

// Virtual Key codes are filled in, but many are not used; instead, we just send
// the unicode for the character in a WM_CHAR message.

SOFTKEY g_rgskKatakana[] = 
    {
//       X   Y Wid Hgt				Characters on Key
//       ------------------------------------------------------------------------------------
        {0,  0,  1,  1,				{KATAKANA_WA,                       },	},
        {1,  0,  1,  1,				{KATAKANA_RA,                       },	},
        {2,  0,  1,  1,				{KATAKANA_YA,                       },	},
        {3,  0,  1,  1,				{KATAKANA_MA,                       },	},
        {4,  0,  1,  1,				{KATAKANA_HA,                       },	},
        {5,  0,  2,  1,				{KANJI_CONFIRM_0, KANJI_CONFIRM_1,},	VK_NOCONVERT},
        {7,  0,  1,  1,				{KATAKANA_NA,                       },	},
        {8,  0,  1,  1,				{KATAKANA_TA,                       },	},
        {9,  0,  1,  1,				{KATAKANA_SA,                       },	},
        {10, 0,  1,  1,				{KATAKANA_KA,                       },	},
        {11, 0,  1,  1,				{KATAKANA_A,                        },	},
        {12, 0,  1,  1,				{SYMBOLS_EXCLAMATION,               },	},
        {13, 0,  1,  1,				{SYMBOLS_QUESTION,                  },	}, 
        {14, 0,  1,  1,				{ROMAN_PLUS,                        },	},
        {15, 0,  1,  1,				{ROMAN_ONE,                         },	},
        {16, 0,  1,  1,				{ROMAN_TWO,                         },	}, 
        {17, 0,  1,  1,				{ROMAN_THREE,                       },	},     
        {0,  1,  1,  1,				{KATAKANA_WO,                       },	},
        {1,  1,  1,  1,				{KATAKANA_RI,                       },	},
        {2,  1,  1,  1,				{KATAKANA_YU,                       },	},
        {3,  1,  1,  1,				{KATAKANA_MI,                       },	},
        {4,  1,  1,  1,				{KATAKANA_HI,                       },	},
        {5,  1,  2,  1,				{KANJI_CONVERT_0,	KANJI_CONVERT_1,},	VK_CONVERT},
        {7,  1,  1,  1,				{KATAKANA_NI,                       },	},
        {8,  1,  1,  1,				{KATAKANA_CHI,                      },	},
        {9,  1,  1,  1,				{KATAKANA_SHI,                      },	},
        {10, 1,  1,  1,				{KATAKANA_KI,                       },	},
        {11, 1,  1,  1,				{KATAKANA_I,                        },	},
        {12, 1,  1,  1,				{SYMBOLS_LOWLINE,                   },	},
        {13, 1,  1,  1,				{SYMBOLS_JAPANESE_DASH,             },	}, 
        {14, 1,  1,  1,				{ROMAN_MINUS,                       },	},
        {15, 1,  1,  1,				{ROMAN_FOUR,                        },	},
        {16, 1,  1,  1,				{ROMAN_FIVE,                        },	}, 
        {17, 1,  1,  1,				{ROMAN_SIX,                         },	},     
        {0,  2,  1,  1,				{KATAKANA_NN,                       },	},
        {1,  2,  1,  1,				{KATAKANA_RU,                       },	},
        {2,  2,  1,  1,				{KATAKANA_YO,                       },	},
        {3,  2,  1,  1,				{KATAKANA_MU,                       },	},
        {4,  2,  1,  1,				{KATAKANA_HU,                       },	},
        {5,  2,  2,  1,				{KANJI_SMALL_0,	KANJI_SMALL_1,		},	},
        {7,  2,  1,  1,				{KATAKANA_NU,                       },	},
        {8,  2,  1,  1,				{KATAKANA_TSU,                      },	},
        {9,  2,  1,  1,				{KATAKANA_SU,                       },	},
        {10, 2,  1,  1,				{KATAKANA_KU,                       },	},
        {11, 2,  1,  1,				{KATAKANA_U,                        },	},
        {12, 2,  1,  1,				{SYMBOLS_PERCENT,                   },	},
        {13, 2,  1,  1,				{SYMBOLS_AMPERSAND,                 },	}, 
        {14, 2,  1,  1,				{ROMAN_SOLIDUS,                     },	},
        {15, 2,  1,  1,				{ROMAN_SEVEN,                       },	},
        {16, 2,  1,  1,				{ROMAN_EIGHT,                       },	}, 
        {17, 2,  1,  1,				{ROMAN_NINE,                        },	},     
        {0,  3,  1,  1,				{SYMBOLS_IDEO_PERIOD,               },	},
        {1,  3,  1,  1,				{KATAKANA_RE,                       },	},
        {2,  3,  1,  1,				{SYMBOLS_ROMAN_LEFT_PAREN,          },	},
        {3,  3,  1,  1,				{KATAKANA_ME,                       },	},
        {4,  3,  1,  1,				{KATAKANA_HE,                       },	},
        {5,  3,  2,  1,				{KANJI_DELETE_0,  KANJI_DELETE_1,	},	VK_BACK},
        {7,  3,  1,  1,				{KATAKANA_NE,                       },	},
        {8,  3,  1,  1,				{KATAKANA_TE,                       },	},
        {9,  3,  1,  1,				{KATAKANA_SE,                       },	},
        {10, 3,  1,  1,				{KATAKANA_KE,                       },	},
        {11, 3,  1,  1,				{KATAKANA_E,                        },	},
        {12, 3,  1,  1,				{SYMBOLS_JAPANESE_LEFT_PAREN,       },	},
        {13, 3,  1,  1,				{SYMBOLS_JAPANESE_RIGHT_PAREN,      },	}, 
        {14, 3,  1,  1,				{ROMAN_EQUALS,                      },	},
        {15, 3,  1,  1,				{ROMAN_ASTERISK,                    },	},
        {16, 3,  1,  1,				{ROMAN_ZERO,                        },	}, 
        {17, 3,  1,  1,				{ROMAN_TILDE,                       },	}, 
        {0,  4,  1,  1,				{SYMBOLS_IDEO_COMMA,                },	},
        {1,  4,  1,  1,				{KATAKANA_RO,                       },	},
        {2,  4,  1,  1,				{SYMBOLS_ROMAN_RIGHT_PAREN,         },	},
        {3,  4,  1,  1,				{KATAKANA_MO,                       },	},
        {4,  4,  1,  1,				{KATAKANA_HO,                       },	},
        {5,  4,  1,  1,				{SYMBOLS_DAKUTEN,                   },	},
        {6,  4,  1,  1,				{SYMBOLS_HANDAKUTEN,                },	},
        {7,  4,  1,  1,				{KATAKANA_NO,                       },	},
        {8,  4,  1,  1,				{KATAKANA_TO,                       },	},
        {9,  4,  1,  1,				{KATAKANA_SO,                       },	},
        {10, 4,  1,  1,				{KATAKANA_KO,                       },	},
        {11, 4,  1,  1,				{KATAKANA_O,                        },	},
        {12, 4,  2,  1,				{KANJI_SYMBOLS_0,	KANJI_SYMBOLS_1,},	},
        {14, 4,  1,  1,				{ROMAN_COLON,                       },	},
        {15, 4,  1,  1,				{SYMBOLS_YEN,                       },	},
        {16, 4,  1,  1,				{ROMAN_DECIMAL,                     },	},
        {17, 4,  1,  1,				{ROMAN_NUMBER,                      },	},
        {0,  5,  1,  1,				{KATAKANA_SWITCH,                   },	},
        {1,  5,  3,  1,				{KANJI_HALF_0,	KANJI_HALF_1, KANJI_HALF_2, KANJI_HALF_3,},	},
        {4,  5,  3,  1,				{KANJI_SPACE_0,  KANJI_SPACE_1,		},	VK_SPACE},
        {7,  5,  5,  1,				{KANJI_CLOSE_0,	KANJI_CLOSE_1, KANJI_CLOSE_2, KANJI_CLOSE_3, KANJI_CLOSE_4, KANJI_CLOSE_5,},	VK_ESCAPE},
        {12, 5,  2,  1,				{KANJI_ENGLISH_0,	KANJI_ENGLISH_1,},},
        {14, 5,  1,  1,				{SYMBOLS_LEFT,                      },	VK_LEFT}, 
        {15, 5,  1,  1,				{SYMBOLS_UP,                        },	VK_UP}, 
        {16, 5,  1,  1,				{SYMBOLS_RIGHT,                     },	VK_RIGHT}, 
        {17, 5,  1,  1,				{SYMBOLS_DOWN,                      },	VK_DOWN}, 
    };

WORD g_cKatakanaKeys = sizeof(g_rgskKatakana) / sizeof(SOFTKEY);  // number of keys on katakana keyboard

// map from katakan -> half-height -> half-width -> half-height and half-width -> dakuten -> handakuten;
// value is 0 if the character doesn't exist
KATAKANA_MAP g_rgKatakanaMap[] =
    {
// Katakana UNICODE     |  Half-Height    | Half-Width        | Half-width & height | Dakuten     | Handakuten
// -----------------------------------------------------------------------------------------------------------

/* KATAKANA_A_HH       */ {0,               KATAKANA_A_HHHW,    0,                  0,              0},
/* KATAKANA_A          */ {KATAKANA_A_HH,   KATAKANA_A_HW,      KATAKANA_A_HHHW,    0,              0},  
/* KATAKANA_I_HH       */ {0,               KATAKANA_I_HHHW,    0,                  0,              0},    
/* KATAKANA_I          */ {KATAKANA_I_HH,   KATAKANA_I_HW,      KATAKANA_I_HHHW,    0,              0},  
/* KATAKANA_U_HH       */ {0,               KATAKANA_U_HHHW,    0,                  0,              0},    
/* KATAKANA_U          */ {KATAKANA_U_HH,   KATAKANA_U_HW,      KATAKANA_U_HHHW,    KATAKANA_U_DK,  0},  
/* KATAKANA_E_HH       */ {0,               KATAKANA_E_HHHW,    0,                  0,              0},    
/* KATAKANA_E          */ {KATAKANA_E_HH,   KATAKANA_E_HW,      KATAKANA_E_HHHW,    0,              0},  
/* KATAKANA_O_HH       */ {0,               KATAKANA_O_HHHW,    0,                  0,              0},    
/* KATAKANA_O          */ {KATAKANA_O_HH,   KATAKANA_O_HW,      KATAKANA_O_HHHW,    0,              0},
/* KATAKANA_KA         */ {KATAKANA_KA_HH,  KATAKANA_KA_HW,     0,                  KATAKANA_KA_DK, 0},
/* KATAKANA_KA_DK      */ {0,               0,                  0,                  0,              0},
/* KATAKANA_KI         */ {0,               KATAKANA_KI_HW,     0,                  KATAKANA_KI_DK, 0},
/* KATAKANA_KI_DK      */ {0,               0,                  0,                  0,              0},
/* KATAKANA_KU         */ {0,               KATAKANA_KU_HW,     0,                  KATAKANA_KU_DK, 0},
/* KATAKANA_KU_DK      */ {0,               0,                  0,                  0,              0},
/* KATAKANA_KE         */ {KATAKANA_KE_HH,  KATAKANA_KE_HW,     0,                  KATAKANA_KE_DK, 0},
/* KATAKANA_KE_DK      */ {0,               0,                  0,                  0,              0},
/* KATAKANA_KO         */ {0,               KATAKANA_KO_HW,     0,                  KATAKANA_KO_DK, 0},
/* KATAKANA_KO_DK      */ {0,               0,                  0,                  0,              0},
/* KATAKANA_SA         */ {0,               KATAKANA_SA_HW,     0,                  KATAKANA_SA_DK, 0},
/* KATAKANA_SA_DK      */ {0,               0,                  0,                  0,              0},
/* KATAKANA_SHI        */ {0,               KATAKANA_SHI_HW,    0,                  KATAKANA_SHI_DK,0},
/* KATAKANA_SHI_DK     */ {0,               0,                  0,                  0,              0},
/* KATAKANA_SU         */ {0,               KATAKANA_SU_HW,     0,                  KATAKANA_SU_DK, 0},
/* KATAKANA_SU_DK      */ {0,               0,                  0,                  0,              0},
/* KATAKANA_SE         */ {0,               KATAKANA_SE_HW,     0,                  KATAKANA_SE_DK, 0},
/* KATAKANA_SE_DK      */ {0,               0,                  0,                  0,              0},
/* KATAKANA_SO         */ {0,               KATAKANA_SO_HW,     0,                  KATAKANA_SO_DK, 0},
/* KATAKANA_SO_DK      */ {0,               0,                  0,                  0,              0},
/* KATAKANA_TA         */ {0,               KATAKANA_TA_HW,     0,                  KATAKANA_TA_DK, 0},
/* KATAKANA_TA_DK      */ {0,               0,                  0,                  0,              0},
/* KATAKANA_CHI        */ {0,               KATAKANA_CHI_HW,    0,                  KATAKANA_CHI_DK,0},
/* KATAKANA_CHI_DK     */ {0,               0,                  0,                  0,              0},
/* KATAKANA_TSU_HH     */ {0,               KATAKANA_TSU_HHHW,  0,                  0,              0},
/* KATAKANA_TSU        */ {KATAKANA_TSU_HH, KATAKANA_TSU_HW,    KATAKANA_TSU_HHHW,  KATAKANA_TSU_DK,0},
/* KATAKANA_TSU_DK     */ {0,               0,                  0,                  0,              0},
/* KATAKANA_TE         */ {0,               KATAKANA_TE_HW,     0,                  KATAKANA_TE_DK, 0},
/* KATAKANA_TE_DK      */ {0,               0,                  0,                  0,              0},
/* KATAKANA_TO         */ {0,               KATAKANA_TO_HW,     0,                  KATAKANA_TO_DK, 0},
/* KATAKANA_TO_DK      */ {0,               0,                  0,                  0,              0},
/* KATAKANA_NA         */ {0,               KATAKANA_NA_HW,     0,                  0,              0},
/* KATAKANA_NI         */ {0,               KATAKANA_NI_HW,     0,                  0,              0},
/* KATAKANA_NU         */ {0,               KATAKANA_NU_HW,     0,                  0,              0},
/* KATAKANA_NE         */ {0,               KATAKANA_NE_HW,     0,                  0,              0},
/* KATAKANA_NO         */ {0,               KATAKANA_NO_HW,     0,                  0,              0},
/* KATAKANA_HA         */ {0,               KATAKANA_HA_HW,     0,                  KATAKANA_HA_DK, KATAKANA_HA_HK},
/* KATAKANA_HA_DK      */ {0,               0,                  0,                  0,              0},
/* KATAKANA_HA_HK      */ {0,               0,                  0,                  0,              0},
/* KATAKANA_HI         */ {0,               KATAKANA_HI_HW,     0,                  KATAKANA_HI_DK, KATAKANA_HI_HK},
/* KATAKANA_HI_DK      */ {0,               0,                  0,                  0,              0},
/* KATAKANA_HI_HK      */ {0,               0,                  0,                  0,              0},
/* KATAKANA_HU         */ {0,               KATAKANA_HU_HW,     0,                  KATAKANA_HU_DK, KATAKANA_HU_HK},
/* KATAKANA_HU_DK      */ {0,               0,                  0,                  0,              0},
/* KATAKANA_HU_HK      */ {0,               0,                  0,                  0,              0},
/* KATAKANA_HE         */ {0,               KATAKANA_HE_HW,     0,                  KATAKANA_HE_DK, KATAKANA_HE_HK},
/* KATAKANA_HE_DK      */ {0,               0,                  0,                  0,              0},
/* KATAKANA_HE_HK      */ {0,               0,                  0,                  0,              0},
/* KATAKANA_HO         */ {0,               KATAKANA_HO_HW,     0,                  KATAKANA_HO_DK, KATAKANA_HO_HK},
/* KATAKANA_HO_DK      */ {0,               0,                  0,                  0,              0},
/* KATAKANA_HO_HK      */ {0,               0,                  0,                  0,              0},
/* KATAKANA_MA         */ {0,               KATAKANA_MA_HW,     0,                  0,              0},
/* KATAKANA_MI         */ {0,               KATAKANA_MI_HW,     0,                  0,              0},
/* KATAKANA_MU         */ {0,               KATAKANA_MU_HW,     0,                  0,              0},
/* KATAKANA_ME         */ {0,               KATAKANA_ME_HW,     0,                  0,              0},
/* KATAKANA_MO         */ {0,               KATAKANA_MO_HW,     0,                  0,              0},
/* KATAKANA_YA_HH      */ {0,               KATAKANA_YA_HHHW,   0,                  0,              0},
/* KATAKANA_YA         */ {KATAKANA_YA_HH,  KATAKANA_YA_HW,     KATAKANA_YA_HHHW,   0,              0},
/* KATAKANA_YU_HH      */ {0,               KATAKANA_YU_HHHW,   0,                  0,              0},
/* KATAKANA_YU         */ {KATAKANA_YU_HH,  KATAKANA_YU_HW,     KATAKANA_YU_HHHW,   0,              0},
/* KATAKANA_YO_HH      */ {0,               KATAKANA_YO_HHHW,   0,                  0,              0},
/* KATAKANA_YO         */ {KATAKANA_YO_HH,  KATAKANA_YO_HW,     KATAKANA_YO_HHHW,   0,              0},
/* KATAKANA_RA         */ {0,               KATAKANA_RA_HW,     0,                  0,              0},
/* KATAKANA_RI         */ {0,               KATAKANA_RI_HW,     0,                  0,              0},
/* KATAKANA_RU         */ {0,               KATAKANA_RU_HW,     0,                  0,              0},
/* KATAKANA_RE         */ {0,               KATAKANA_RE_HW,     0,                  0,              0},
/* KATAKANA_RO         */ {0,               KATAKANA_RO_HW,     0,                  0,              0},
/* KATAKANA_WA_HH      */ {0,               0,                  0,                  0,              0},
/* KATAKANA_WA         */ {KATAKANA_WA_HH,  KATAKANA_WA_HW,     0,                  0,              0},
/* KATAKANA_UNKNOWN1   */ {0,               0,                  0,                  0,              0},
/* KATAKANA_UNKNOWN2   */ {0,               0,                  0,                  0,              0},
/* KATAKANA_WO         */ {0,               KATAKANA_WO_HW,     0,                  0,              0},
/* KATAKANA_NN         */ {0,               KATAKANA_NN_HW,     0,                  0,              0},
/* KATAKANA_U_DK       */ {0,               0,                  0,                  0,              0},
/* KATAKANA_KA_HH      */ {0,               0,                  0,                  0,              0},
/* KATAKANA_KE_HH      */ {0,               0,                  0,                  0,              0}
    };

/*
        {KATAKANA_A,            (KATAKANA_A - 1),       (FIRST_HW + SYLLABLE_A - SYLLABLE_START),   0xff67,             0,                  0                   },      
        {KATAKANA_I,            (KATAKANA_I - 1),       (FIRST_HW + SYLLABLE_I - SYLLABLE_START),   0xff68,             0,                  0                   },
        {KATAKANA_U,            (KATAKANA_U - 1),       (FIRST_HW + SYLLABLE_U - SYLLABLE_START),   0xff69,             0x30f4,             0                   },
        {KATAKANA_E,            (KATAKANA_E - 1),       (FIRST_HW + SYLLABLE_E - SYLLABLE_START),   0xff6a,             0,                  0                   },
        {KATAKANA_O,            (KATAKANA_O - 1),       (FIRST_HW + SYLLABLE_O - SYLLABLE_START),   0xff6b,             0,                  0                   },
        {KATAKANA_KA,           0x30f5,                 (FIRST_HW + SYLLABLE_KA - SYLLABLE_START),  0,                  (KATAKANA_KA + 1),  0                   },
        {KATAKANA_KI,           0,                      (FIRST_HW + SYLLABLE_KI - SYLLABLE_START),  0,                  (KATAKANA_KI + 1),  0                   },
        {KATAKANA_KU,           0,                      (FIRST_HW + SYLLABLE_KU - SYLLABLE_START),  0,                  (KATAKANA_KU + 1),  0                   },
        {KATAKANA_KE,           0x30f6,                 (FIRST_HW + SYLLABLE_KE - SYLLABLE_START),  0,                  (KATAKANA_KE + 1),  0                   },
        {KATAKANA_KO,           0,                      (FIRST_HW + SYLLABLE_KO - SYLLABLE_START),  0,                  (KATAKANA_KO + 1),  0                   },
        {KATAKANA_SA,           0,                      (FIRST_HW + SYLLABLE_SA - SYLLABLE_START),  0,                  (KATAKANA_SA + 1),  0                   },
        {KATAKANA_SHI,          0,                      (FIRST_HW + SYLLABLE_SHI - SYLLABLE_START), 0,                  (KATAKANA_SHI + 1), 0                   },
        {KATAKANA_SU,           0,                      (FIRST_HW + SYLLABLE_SU - SYLLABLE_START),  0,                  (KATAKANA_SU + 1),  0                   },
        {KATAKANA_SE,           0,                      (FIRST_HW + SYLLABLE_SE - SYLLABLE_START),  0,                  (KATAKANA_SE + 1),  0                   },
        {KATAKANA_SO,           0,                      (FIRST_HW + SYLLABLE_SO - SYLLABLE_START),  0,                  (KATAKANA_SO + 1),  0                   },
        {KATAKANA_TA,           0,                      (FIRST_HW + SYLLABLE_TA - SYLLABLE_START),  0,                  (KATAKANA_TA + 1),  0                   },
        {KATAKANA_CHI,          0,                      (FIRST_HW + SYLLABLE_CHI - SYLLABLE_START), 0,                  (KATAKANA_CHI + 1), 0                   },
        {KATAKANA_TSU,          (KATAKANA_TSU - 1),     (FIRST_HW + SYLLABLE_TSU - SYLLABLE_START), 0xff6f,             (KATAKANA_TSU + 1), 0                   },
        {KATAKANA_TE,           0,                      (FIRST_HW + SYLLABLE_TE - SYLLABLE_START),  0,                  (KATAKANA_TE + 1),  0                   },
        {KATAKANA_TO,           0,                      (FIRST_HW + SYLLABLE_TO - SYLLABLE_START),  0,                  (KATAKANA_TO + 1),  0                   },
        {KATAKANA_NA,           0,                      (FIRST_HW + SYLLABLE_NA - SYLLABLE_START),  0,                  0,                  0                   },
        {KATAKANA_NI,           0,                      (FIRST_HW + SYLLABLE_NI - SYLLABLE_START),  0,                  0,                  0                   },
        {KATAKANA_NU,           0,                      (FIRST_HW + SYLLABLE_NU - SYLLABLE_START),  0,                  0,                  0                   },
        {KATAKANA_NE,           0,                      (FIRST_HW + SYLLABLE_NE - SYLLABLE_START),  0,                  0,                  0                   },
        {KATAKANA_NO,           0,                      (FIRST_HW + SYLLABLE_NO - SYLLABLE_START),  0,                  0,                  0                   },
        {KATAKANA_HA,           0,                      (FIRST_HW + SYLLABLE_HA - SYLLABLE_START),  0,                  (KATAKANA_HA + 1),  (KATAKANA_HA + 2)   },
        {KATAKANA_HI,           0,                      (FIRST_HW + SYLLABLE_HI - SYLLABLE_START),  0,                  (KATAKANA_HI + 1),  (KATAKANA_HI + 2)   },
        {KATAKANA_HU,           0,                      (FIRST_HW + SYLLABLE_HU - SYLLABLE_START),  0,                  (KATAKANA_HU + 1),  (KATAKANA_HU + 2)   },
        {KATAKANA_HE,           0,                      (FIRST_HW + SYLLABLE_HE - SYLLABLE_START),  0,                  (KATAKANA_HE + 1),  (KATAKANA_HE + 2)   },
        {KATAKANA_HO,           0,                      (FIRST_HW + SYLLABLE_HO - SYLLABLE_START),  0,                  (KATAKANA_HO + 1),  (KATAKANA_HO + 2)   },
        {KATAKANA_MA,           0,                      (FIRST_HW + SYLLABLE_MA - SYLLABLE_START),  0,                  0,                  0                   },
        {KATAKANA_MI,           0,                      (FIRST_HW + SYLLABLE_MI - SYLLABLE_START),  0,                  0,                  0                   },
        {KATAKANA_MU,           0,                      (FIRST_HW + SYLLABLE_MU - SYLLABLE_START),  0,                  0,                  0                   },
        {KATAKANA_ME,           0,                      (FIRST_HW + SYLLABLE_ME - SYLLABLE_START),  0,                  0,                  0                   },
        {KATAKANA_MO,           0,                      (FIRST_HW + SYLLABLE_MO - SYLLABLE_START),  0,                  0,                  0                   },
        {KATAKANA_YA,           (KATAKANA_YA - 1),      (FIRST_HW + SYLLABLE_YA - SYLLABLE_START),  0xff6c,             0,                  0                   },
        {KATAKANA_YU,           (KATAKANA_YU - 1),      (FIRST_HW + SYLLABLE_YU - SYLLABLE_START),  0xff6d,             0,                  0                   },
        {KATAKANA_YO,           (KATAKANA_YO - 1),      (FIRST_HW + SYLLABLE_YO - SYLLABLE_START),  0xff6e,             0,                  0                   },
        {KATAKANA_RA,           0,                      (FIRST_HW + SYLLABLE_RA - SYLLABLE_START),  0,                  0,                  0                   },
        {KATAKANA_RI,           0,                      (FIRST_HW + SYLLABLE_RI - SYLLABLE_START),  0,                  0,                  0                   },
        {KATAKANA_RU,           0,                      (FIRST_HW + SYLLABLE_RU - SYLLABLE_START),  0,                  0,                  0                   },
        {KATAKANA_RE,           0,                      (FIRST_HW + SYLLABLE_RE - SYLLABLE_START),  0,                  0,                  0                   },
        {KATAKANA_RO,           0,                      (FIRST_HW + SYLLABLE_RO - SYLLABLE_START),  0,                  0,                  0                   },
        {KATAKANA_WA,           (KATAKANA_WA - 1),      (FIRST_HW + SYLLABLE_WA - SYLLABLE_START),  0,                  0,                  0                   },
        {KATAKANA_WO,           (KATAKANA_WO - 1),      0xff66,                                     0x5566,             0,                  0                   },
        {KATAKANA_NN,           0,                      0xff9d,                                     0,                  0,                  0                   }
*/

#endif

// katakana.cxx
