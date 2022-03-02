#include "golf/golf.h"

#include "common/debug_console.h"
#include "common/graphics.h"
#include "common/log.h"
#include "golf/game.h"
#include "golf/ui.h"

static golf_t golf;
static golf_graphics_t *graphics;

static const char *initial_level_path = "data/levels/level-1.level";

void golf_init(void) {
    golf_data_load(initial_level_path, true);
    snprintf(golf.level_loading_path, GOLF_FILE_MAX_PATH, "%s", initial_level_path);
    golf.state = GOLF_STATE_TITLE_SCREEN;
    golf.title_screen.t = 0;
    graphics = golf_graphics_get();

    golf_game_init();
    golf_ui_init();
}

void golf_update(float dt) {
    switch (golf.state) {
        case GOLF_STATE_TITLE_SCREEN: {
            golf.title_screen.t += dt;
            if (golf_data_get_load_state(golf.level_loading_path) == GOLF_DATA_LOADED) {
                golf.level = golf_data_get_level(golf.level_loading_path);
                golf.state = GOLF_STATE_MAIN_MENU;
            }
            break;
        }
        case GOLF_STATE_MAIN_MENU: {
            break;
        }
        case GOLF_STATE_LOADING_LEVEL: {
            golf.loading_level.t += dt;
            if (golf_data_get_load_state(golf.level_loading_path) == GOLF_DATA_LOADED) {
                golf.level = golf_data_get_level(golf.level_loading_path);
                golf.state = GOLF_STATE_IN_GAME;
                golf_game_start_level();
            }
            break;
        }
        case GOLF_STATE_IN_GAME: {
            break;
        }
    }

    if (golf.state == GOLF_STATE_MAIN_MENU || golf.state == GOLF_STATE_IN_GAME) {
        golf_game_update(dt);
    }
    golf_ui_update(dt);
    golf_debug_console_update(dt);
}

golf_t *golf_get(void) {
    return &golf;
}

void golf_start_level(int level_num) {
    if (golf_data_get_load_state(golf.level_loading_path) != GOLF_DATA_LOADED) {
        golf_log_warning("Trying to load level before previous one has finished loading...");
        return;
    }

    golf.level = NULL;
    golf_data_unload(golf.level_loading_path);

    snprintf(golf.level_loading_path, GOLF_FILE_MAX_PATH, "data/levels/level-%d.level", level_num + 1);
    golf_data_load(golf.level_loading_path, true);
    golf.state = GOLF_STATE_LOADING_LEVEL;
}
