#ifndef _GOLF_GOLF_H
#define _GOLF_GOLF_H

#include "common/data.h"
#include "common/file.h"
#include "common/level.h"

typedef enum golf_state {
    GOLF_STATE_TITLE_SCREEN,
    GOLF_STATE_MAIN_MENU,
    GOLF_STATE_LOADING_LEVEL,
    GOLF_STATE_IN_GAME,
} golf_state_t;

typedef struct golf {
    golf_state_t state;
    union {
        struct {
            float t;
        } title_screen;

        struct {
            int t;
        } main_menu;

        struct {
            float t;
        } loading_level;

        struct {
            int t;  
        } in_level;
    };

    char level_loading_path[GOLF_FILE_MAX_PATH];
    golf_level_t *level;
} golf_t;

void golf_init(void);
void golf_update(float dt);
golf_t *golf_get(void);
void golf_start_level(int level_num);

#endif
