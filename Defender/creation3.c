/*
** EPITECH PROJECT, 2021
** creation3
** File description:
** creation3
*/

#include "include/my.h"
#include "include/struct.h"

void set_texture3(defender_t *defender)
{
    sfSprite_setTexture(defender->shot, defender->text_shot, sfTrue);
    sfSprite_setTexture(defender->shot2, defender->text_shot2, sfTrue);
    sfSprite_setTexture(defender->m_htp, defender->text_m_htp, sfTrue);
    sfSprite_setTexture(defender->htp, defender->text_htp, sfTrue);
    sfSprite_setTexture(defender->m_build, defender->text_m_b, sfTrue);
    defender->anim_shot3 = (sfIntRect) {0, 0, 170, 110};
    defender->anim_shot4 = (sfIntRect) {0, 0, 170, 110};
    defender->anim_shot5 = (sfIntRect) {0, 0, 170, 110};
    defender->anim_shot6 = (sfIntRect) {0, 0, 170, 110};
    defender->anim_shot7 = (sfIntRect) {0, 0, 170, 110};
    sfSprite_setTexture(defender->shot3, defender->text_shot3, sfTrue);
    sfSprite_setTexture(defender->shot4, defender->text_shot4, sfTrue);
    sfSprite_setTexture(defender->shot5, defender->text_shot5, sfTrue);
    sfSprite_setTexture(defender->shot6, defender->text_shot6, sfTrue);
    sfSprite_setTexture(defender->shot7, defender->text_shot7, sfTrue);
    sfSprite_setTexture(defender->tesla1, defender->text_tesla1, sfTrue);
    sfSprite_setTexture(defender->tesla2, defender->text_tesla2, sfTrue);
    sfSprite_setTexture(defender->tesla3, defender->text_tesla3, sfTrue);
    sfSprite_setTexture(defender->tesla4, defender->text_tesla4, sfTrue);
    set_texture4(defender);
}

void set_position(defender_t *defender)
{
    defender->pos_ms = sfMouse_getPositionRenderWindow(defender->window);
    sfSprite_setPosition(defender->butt_play, defender->pos_butt_play);
    sfSprite_setPosition(defender->butt_back, defender->pos_butt_back);
    sfSprite_setPosition(defender->butt_sett, defender->pos_butt_sett);
    sfSprite_setPosition(defender->arrow, defender->pos_arrow);
    sfSprite_setPosition(defender->butt_60, defender->pos_butt_60);
    sfSprite_setPosition(defender->butt_120, defender->pos_butt_12O);
    sfSprite_setPosition(defender->butt_180, defender->pos_butt_180);
    sfSprite_setPosition(defender->enemy, defender->pos_enemy);
    sfSprite_setPosition(defender->cs, (sfVector2f) {defender->pos_ms.x - 15,
                                                    defender->pos_ms.y - 20});
    sfSprite_setPosition(defender->twer1, defender->pos_twer1);
    sfSprite_setPosition(defender->twer2, defender->pos_twer2);
    sfSprite_setPosition(defender->twer3, defender->pos_twer3);
    sfSprite_setPosition(defender->twer4, defender->pos_twer4);
    sfSprite_setPosition(defender->twer5, defender->pos_twer5);
    sfSprite_setPosition(defender->twer6, defender->pos_twer6);
    sfSprite_setPosition(defender->twer7, defender->pos_twer7);
    set_position2(defender);
}

void set_position2(defender_t *defender)
{
    sfSprite_setPosition(defender->grass1, defender->pos_grass1);
    sfSprite_setPosition(defender->grass2, defender->pos_grass2);
    sfSprite_setPosition(defender->grass3, defender->pos_grass3);
    sfSprite_setPosition(defender->grass4, defender->pos_grass4);
    sfSprite_setPosition(defender->grass5, defender->pos_grass5);
    sfSprite_setPosition(defender->grass6, defender->pos_grass6);
    sfSprite_setPosition(defender->grass7, defender->pos_grass7);
    sfSprite_setPosition(defender->resume, defender->pos_resume);
    sfSprite_setPosition(defender->menu, defender->pos_menu);
    sfSprite_setPosition(defender->esc, defender->pos_esc);
    sfSprite_setPosition(defender->vie1, defender->pos_vie1);
    sfSprite_setPosition(defender->vie2, defender->pos_vie2);
    sfSprite_setPosition(defender->vie3, defender->pos_vie3);
    sfSprite_setPosition(defender->shot, defender->pos_shot);
    sfSprite_setPosition(defender->shot2, defender->pos_shot2);
    sfSprite_setPosition(defender->htp, defender->pos_htp);
    sfSprite_setPosition(defender->m_build, defender->pos_m_build);
    set_position3(defender);
}

void sprite3(defender_t *defender)
{
    defender->shot2 = sfSprite_create();
    defender->m_htp = sfSprite_create();
    defender->htp = sfSprite_create();
    defender->m_build = sfSprite_create();
    defender->shot3 = sfSprite_create();
    defender->shot4 = sfSprite_create();
    defender->shot5 = sfSprite_create();
    defender->shot6 = sfSprite_create();
    defender->shot7 = sfSprite_create();
    defender->tesla1 = sfSprite_create();
    defender->tesla2 = sfSprite_create();
    defender->tesla3 = sfSprite_create();
    defender->tesla4 = sfSprite_create();
    defender->tesla5 = sfSprite_create();
    defender->tesla6 = sfSprite_create();
    defender->tesla7 = sfSprite_create();
    defender->slow1 = sfSprite_create();
    defender->slow2 = sfSprite_create();
    defender->slow3 = sfSprite_create();
    sprite4(defender);
}

void texture3(defender_t *defender)
{
    defender->text_htp = sfTexture_createFromFile("tools/htp.png", NULL);
    defender->text_m_b = sfTexture_createFromFile("tools/m_twr.png", NULL);
    defender->text_shot3 = sfTexture_createFromFile("tools/shotani.png", NULL);
    defender->text_shot4 = sfTexture_createFromFile("tools/shotani.png", NULL);
    defender->text_shot5 = sfTexture_createFromFile("tools/shotani.png", NULL);
    defender->text_shot6 = sfTexture_createFromFile("tools/shotani.png", NULL);
    defender->text_shot7 = sfTexture_createFromFile("tools/shotani.png", NULL);
    defender->text_tesla1 = sfTexture_createFromFile("tools/tesla.png", NULL);
    defender->text_tesla2 = sfTexture_createFromFile("tools/tesla.png", NULL);
    defender->text_tesla3 = sfTexture_createFromFile("tools/tesla.png", NULL);
    defender->text_tesla4 = sfTexture_createFromFile("tools/tesla.png", NULL);
    defender->text_tesla5 = sfTexture_createFromFile("tools/tesla.png", NULL);
    defender->text_tesla6 = sfTexture_createFromFile("tools/tesla.png", NULL);
    defender->text_tesla7 = sfTexture_createFromFile("tools/tesla.png", NULL);
    defender->text_slow1 = sfTexture_createFromFile("tools/slow.png", NULL);
    defender->text_slow2 = sfTexture_createFromFile("tools/slow.png", NULL);
    defender->text_slow3 = sfTexture_createFromFile("tools/slow.png", NULL);
    defender->text_slow4 = sfTexture_createFromFile("tools/slow.png", NULL);
    defender->text_slow5 = sfTexture_createFromFile("tools/slow.png", NULL);
    texture4(defender);
}