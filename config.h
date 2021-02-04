#pragma once

#ifdef AUDIO_ENABLE
  #define STARTUP_SONG SONG(NO_SOUND)
  #define NO_MUSIC_MODE
#endif

#define TAPPING_TERM 200
#define USB_MAX_POWER_CONSUMPTION 100 // required to be able to use the keyboard with iPad

