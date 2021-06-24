/*
** EPITECH PROJECT, 2020
** my
** File description:
** task02 day09
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Window/Types.h>
#include <SFML/System.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Time.h>
#include <SFML/System/Clock.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ncurses.h>
#include <curses.h>
#include <string.h>

typedef struct rpg_s
{
    sfEvent event;
    sfView *view;

    float *coord_view;
    float *save_coord_view;
    char **map;
    char **dialog;
    char **name;
    int main_menu;
    int pause_menu;
    int pause_menu2;
    int pause_menux;
    int pause_menuy;
    int walk;
    int walk_toward;
    int walk_backward;
    int walk_left;
    int walk_right;
    int top_map;
    int left_map;
    int x_character;
    int y_character;
    int collision_top;
    int collision_bot;
    int collision_left;
    int collision_right;
    int speech;
    int lag_button;
    int inventaire;
    int set_pos;
    int step_of_game;
    int back_from_pause_menu;
    int move_hand_menu_combat;
    int attaque_alde;
    int defense_alde;
    int attaque_jason;
    int defense_jason;
    int attaque_the_rock;
    int defense_the_rock;
    int song_for_kaaris;
    int save_settings;
    int if_already_cutscene;
    int if_in_pause_menu;

    float character_seconds;
    float dialog_seconds;
    float volume;
    float cutscene_seconds;

    sfTime character_time;
    sfTime dialog_time;
    sfTime cutscene_time;

    sfClock *character_clock;
    sfClock *lag_button_clock;
    sfClock *dialog_clock;
    sfClock *download_cut_scene_clock;

    sfMusic *music_fond;

    sfSprite *map_spr;
    sfSprite *character_spr;
    sfSprite *main_menu_bckg_spr;
    sfSprite *hand_selection_spr;
    sfSprite *pause_menu_spr;
    sfSprite *speech_spr;
    sfSprite *set_spr;
    sfSprite *set_menu_spr;
    sfSprite *inventory_spr;
    sfSprite *select_spr;
    sfSprite *htp_logo_spr;
    sfSprite *htp_menu_spr;
    sfSprite *menu_combat_alde_spr;
    sfSprite *menu_combat_jason_spr;
    sfSprite *menu_c_the_rock_spr;
    sfSprite *life_sard_alde_spr;
    sfSprite *life_alde_spr;
    sfSprite *life_sard_jason_spr;
    sfSprite *life_jason_spr;
    sfSprite *life_sard_rock_spr;
    sfSprite *life_rock_spr;
    sfSprite *cut_scene_spr;
    sfSprite *download_cut_scene_spr;
    sfSprite *item_bob_lorenzo_spr;
    sfSprite *item_dollars_spr;
    sfSprite *item_wati_spr;
    sfSprite *item_bugatti_spr;
    sfSprite *item_ak_spr;
    sfSprite *item_alk_spr;
    sfSprite *end_menu_spr;

    sfIntRect character_rect;
    sfIntRect swimmer01_rect;
    sfIntRect life_sard_alde_rect;
    sfIntRect life_alde_rect;
    sfIntRect life_sard_jason_rec;
    sfIntRect life_jason_rect;
    sfIntRect life_sard_rock_rect;
    sfIntRect life_rock_rect;
    sfIntRect download_cut_scene_rect;

    sfTexture *map_text;
    sfTexture *character_text;
    sfTexture *main_m_bckg_text;
    sfTexture *hand_s_text;
    sfTexture *pause_menu_text;
    sfTexture *speech_text;
    sfTexture *set_text;
    sfTexture *set_menu_text;
    sfTexture *inventory_text;
    sfTexture *select_text;
    sfTexture *swimmer01_text;
    sfTexture *htp_logo_text;
    sfTexture *htp_menu_text;
    sfTexture *menu_combat_alde_text;
    sfTexture *menu_combat_jason_text;
    sfTexture *menu_combat_the_rock_text;
    sfTexture *life_bar_text;
    sfTexture *cut_scene_text;
    sfTexture *download_cut_scene_text;
    sfTexture *item_bob_text;
    sfTexture *item_dollars_text;
    sfTexture *item_wati_text;
    sfTexture *item_bugatti_text;
    sfTexture *item_ak_text;
    sfTexture *item_alk_text;
    sfTexture *end_menu_text;

    sfVector2f character_vect;
    sfVector2f hand_selection_vect;
    sfVector2f pause_menu_vect;
    sfVector2f speech_vect;
    sfVector2f set_vect;
    sfVector2f main_menu_vect;
    sfVector2f inventory_vect;
    sfVector2f select_vect;
    sfVector2f swimmer01_vect;
    sfVector2f htp_logo_vect;
    sfVector2f menu_combat_alde_vect;
    sfVector2f menu_comb_jason_vect;
    sfVector2f menu_c_the_rock_vect;
    sfVector2f life_sardocho_alde_vect;
    sfVector2f life_alde_vect;
    sfVector2f life_sard_jason_vect;
    sfVector2f life_jason_vect;
    sfVector2f life_sardocho_rock_vect;
    sfVector2f life_rock_vect;
    sfVector2f download_cute_scene_vect;
    sfVector2f item_bob_lorenzo_vect;
    sfVector2f item_dollars_vect;
    sfVector2f item_wati_vect;
    sfVector2f item_bugatti_vect;
    sfVector2f item_ak_vect;
    sfVector2f item_alk_vect;
    sfVector2f end_menu_vect;


    sfText *speech_txt1;
    sfText *speech_txt2;
    sfText *speech_txt3;
    sfText *name_pnj_txt;
    sfText *speech_txt4;

    sfFont *speech_font;

    sfRenderWindow *window;
}rpg_t;

void move_hand_selection_in_menu_combat_the_rock3(rpg_t *rpg);
void move_hand_selection_in_menu_combat_the_rock4(rpg_t *rpg);
void lorenzo_quest1(rpg_t *rpg);
void lorenzo_quest2(rpg_t *rpg);
void lorenzo_quest3(rpg_t *rpg);
void lorenzo_quest4(rpg_t *rpg);
void lorenzo_quest5(rpg_t *rpg);
void lorenzo_quest6(rpg_t *rpg);
void lorenzo_quest7(rpg_t *rpg);
void wich_button(rpg_t *rpg);
void display_pause_menu(rpg_t *rpg);
char **open_file(char *filepath);
char **open_file_dialog(char *filepath);
void lag_button_clock(rpg_t *rpg);
void dialog_clock(rpg_t *rpg);
void display_character(rpg_t *rpg);
void character_clock(rpg_t *rpg);
void wich_button_when_enter_pressed(rpg_t *rpg);
void move_selection_from_inv(rpg_t *rpg);
void move_the_character_in_game(rpg_t *rpg);
void move_hand_selection_in_pause_menu(rpg_t *rpg);
void move_hand_selection_in_main_menu(rpg_t *rpg);
void open_the_inventaire(rpg_t *rpg);
void close_the_pause_menu(rpg_t *rpg);
void close_the_window(rpg_t *rpg);
void do_free(rpg_t *rpg);
int init_everything(rpg_t *rpg);
void init_everything2(rpg_t *rpg);
void init_struct(rpg_t *rpg);
void init_clock(rpg_t *rpg);
void init_character(rpg_t *rpg);
void init_map(rpg_t *rpg);
void init_speech(rpg_t *rpg);
void init_inventory(rpg_t *rpg);
void init_htp_menu(rpg_t *rpg);
void init_text_font(rpg_t *rpg);
void interraction(rpg_t *rpg);
void display_speech(rpg_t *rpg);
void interaction_with_lorenzo(rpg_t *rpg);
void interaction_with_roi_hennok_one(rpg_t *rpg);
void interaction_for_the_end(rpg_t *rpg);
void analyse_event(rpg_t *rpg);
void go_in_game(rpg_t *rpg);
void go_main_menu(rpg_t *rpg);
void go_set_menu(rpg_t *rpg);
void go_htp_menu(rpg_t *rpg);
void gameloop(rpg_t *rpg);
int main(void);
void display_map(rpg_t *rpg);
void display_view(rpg_t *rpg);
void init_main_menu(rpg_t *rpg);
void init_set_menu(rpg_t *rpg);
void display_main_menu(rpg_t *rpg);
void display_set_menu(rpg_t *rpg);
void move_hand_selection_to_right(rpg_t *rpg);
void move_hand_selection_to_left(rpg_t *rpg);
void move_hand_selection_to_high(rpg_t *rpg);
void move_hand_selection_to_high2(rpg_t *rpg);
void move_hand_selection_to_low(rpg_t *rpg);
void move_hand_selection_to_low3(rpg_t *rpg);
void move_hand_selection_to_low2(rpg_t *rpg);
void move_select_to_right(rpg_t *rpg);
void move_select_to_left(rpg_t *rpg);
void move_select_to_down(rpg_t *rpg);
void move_select_to_up(rpg_t *rpg);
void wich_button(rpg_t *rpg);
void select_playing_button(rpg_t *rpg);
void select_quit_button(rpg_t *rpg);
void select_set_button(rpg_t *rpg);
void select_quit_menu_button(rpg_t *rpg);
void select_60_fps(rpg_t *rpg);
void select_120_fps(rpg_t *rpg);
void select_volume_down(rpg_t *rpg);
void select_volume_up(rpg_t *rpg);
void select_htp(rpg_t *rpg);
void select_htp_back(rpg_t *rpg);
void menu_inventory(rpg_t *rpg);
void move_view(rpg_t *rpg);
void move_view2(rpg_t *rpg);
void detect_collision(rpg_t *rpg);
void detect_if_board(rpg_t *rpg);
void init_pause_menu(rpg_t *rpg);
void display_pause_menu(rpg_t *rpg);
void move_hand_selection_to_right_pause(rpg_t *rpg);
void move_hand_selection_to_left_pause(rpg_t *rpg);
void wich_button_pause(rpg_t *rpg);
void select_main_menu_button(rpg_t *rpg);
void select_quit_pause_button(rpg_t *rpg);
void init_menu_combat_alde(rpg_t *rpg);
void init_menu_combat_jason(rpg_t *rpg);
void init_menu_combat_the_rock(rpg_t *rpg);
void go_menu_combat_alde(rpg_t *rpg);
void go_menu_combat_jason(rpg_t *rpg);
void go_menu_combat_the_rock(rpg_t *rpg);
void go_menu_combat_the_rock2(rpg_t *rpg);
void move_hand_selection_in_menu_combat_alde(rpg_t *rpg);
void move_hand_selection_in_menu_combat_alde2(rpg_t *rpg);
void move_hand_selection_in_menu_combat_jason(rpg_t *rpg);
void move_hand_selection_in_menu_combat_jason2(rpg_t *rpg);
void move_hand_selection_in_menu_combat_the_rock(rpg_t *rpg);
void move_hand_selection_in_menu_combat_the_rock2(rpg_t *rpg);
void select_resize_screen(rpg_t *rpg);
void select_save_settings(rpg_t *rpg);
void init_music(rpg_t *rpg);
void move_hand_selection_to_hight_pause(rpg_t *rpg);
void move_hand_selection_to_low_pause(rpg_t *rpg);
void select_settings_pause_button(rpg_t *rpg);
void download_cut_scene_clock(rpg_t *rpg);
void go_cut_scene(rpg_t *rpg);
void interaction_with_lorenzo_quest(rpg_t *rpg);
void interaction_with_booba(rpg_t *rpg);
void interaction_with_booba2(rpg_t *rpg);
void interaction_with_kaaris(rpg_t *rpg);
void interaction_with_kaaris2(rpg_t *rpg);
void interaction_with_lafouine(rpg_t *rpg);
void interaction_with_lafouine2(rpg_t *rpg);
void interaction_with_alkapote(rpg_t *rpg);
void interaction_with_alderiate(rpg_t *rpg);
void interaction_with_jason(rpg_t *rpg);
void interaction_with_the_rock(rpg_t *rpg);
void fighting_system_for_alde(rpg_t *rpg);
void fighting_system_for_jason(rpg_t *rpg);
void fighting_system_for_the_rock(rpg_t *rpg);
void interaction_with_useless_pnj(rpg_t *rpg, int wich_name);
void interaction_with_kaaris_non_nrv(rpg_t *rpg);
void interaction_with_kaaris_non_nrv2(rpg_t *rpg);
void init_cut_scene(rpg_t *rpg);
void init_download_cut_scene(rpg_t *rpg);
void init_life_bars(rpg_t *rpg);
void skip_cut_scene(rpg_t *rpg);
void interraction_with_pnj(rpg_t *rpg);
void display_cut_scene(rpg_t *rpg);
void move_hand_selection_to_low4(rpg_t *rpg);
void go_menu_combat_alde2(rpg_t *rpg);
void go_menu_combat_jason2(rpg_t *rpg);
void init_life_bars2(rpg_t *rpg);
void interaction_with_roi_hennok_one2(rpg_t *rpg);
void init_item_inventory(rpg_t *rpg);
void init_end_menu(rpg_t *rpg);
void set_coord_speech(rpg_t *rpg);
void quit_end_menu(rpg_t *rpg);
void go_to_everything(rpg_t *rpg);
void go_end_menu(rpg_t *rpg);
void menu_inventory_init(rpg_t *rpg);
void menu_inventory_draw_set(rpg_t *rpg);
void menu_inventory_place_items(rpg_t *rpg);

int my_strlen(char const *str);
char **my_str_to_chartab(char *buffer);
char **my_str_to_chartab_dialog(char *buffer);