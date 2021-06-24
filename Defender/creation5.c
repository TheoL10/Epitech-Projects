/*
** EPITECH PROJECT, 2021
** creation5
** File description:
** creation5
*/

#include "include/my.h"
#include "include/struct.h"

void position9(defender_t *defender)
{
    defender->pos_sws2.y = 280;
    defender->pos_sws3.x = 585;
    defender->pos_sws3.y = 510;
    defender->pos_sws4.x = 265;
    defender->pos_sws4.y = 660;
    defender->pos_sws5.x = 910;
    defender->pos_sws5.y = 460;
    defender->pos_sws6.x = 1245;
    defender->pos_sws6.y = 310;
    defender->pos_sws7.x = 910;
    defender->pos_sws7.y = 710;
    defender->pos_slt1.x = 1678;
    defender->pos_slt1.y = 300;
    defender->pos_slt2.x = 1678;
    defender->pos_slt2.y = 478;
    defender->pos_slt3.x = 1678;
    defender->pos_slt3.y = 656;
    defender->pos_slt4.x = 1678;
    defender->pos_slt4.y = 830;
    position10(defender);
}

void texture4(defender_t *defender)
{
    defender->text_slow6 = sfTexture_createFromFile("tools/slow.png", NULL);
    defender->text_slow7 = sfTexture_createFromFile("tools/slow.png", NULL);
    defender->text_rock = sfTexture_createFromFile("tools/rock.png", NULL);
    defender->text_ts = sfTexture_createFromFile("tools/animtesla.png", NULL);
    defender->text_ts2 = sfTexture_createFromFile("tools/animtesla.png", NULL);
    defender->text_ts3 = sfTexture_createFromFile("tools/animtesla.png", NULL);
    defender->text_ts4 = sfTexture_createFromFile("tools/animtesla.png", NULL);
    defender->text_ts5 = sfTexture_createFromFile("tools/animtesla.png", NULL);
    defender->text_ts6 = sfTexture_createFromFile("tools/animtesla.png", NULL);
    defender->text_ts7 = sfTexture_createFromFile("tools/animtesla.png", NULL);
    defender->text_sws = sfTexture_createFromFile("tools/clock.png", NULL);
    defender->text_sws2 = sfTexture_createFromFile("tools/clock.png", NULL);
    defender->text_sws3 = sfTexture_createFromFile("tools/clock.png", NULL);
    defender->text_sws4 = sfTexture_createFromFile("tools/clock.png", NULL);
    defender->text_sws5 = sfTexture_createFromFile("tools/clock.png", NULL);
    defender->text_sws6 = sfTexture_createFromFile("tools/clock.png", NULL);
    defender->text_sws7 = sfTexture_createFromFile("tools/clock.png", NULL);
    defender->text_slt1 = sfTexture_createFromFile("tools/select.png", NULL);
    defender->text_slt2 = sfTexture_createFromFile("tools/select.png", NULL);
    texture5(defender);
}

void position7(defender_t *defender)
{
    defender->pos_tesla5.y = 590;
    defender->pos_tesla6.x = 1400;
    defender->pos_tesla6.y = 410;
    defender->pos_tesla7.x = 1080;
    defender->pos_tesla7.y = 800;
    defender->pos_slow1.x = 430;
    defender->pos_slow1.y = 250;
    defender->pos_slow2.x = 760;
    defender->pos_slow2.y = 410;
    defender->pos_slow3.x = 760;
    defender->pos_slow3.y = 600;
    defender->pos_slow4.x = 430;
    defender->pos_slow4.y = 780;
    defender->pos_slow5.x = 1080;
    defender->pos_slow5.y = 590;
    defender->pos_slow6.x = 1400;
    defender->pos_slow6.y = 410;
    defender->pos_slow7.x = 1080;
    defender->pos_slow7.y = 800;
    position8(defender);
}

void position8(defender_t *defender)
{
    defender->pos_rock.x = 905;
    defender->pos_rock.y = 600;
    defender->pos_ts.x = 200;
    defender->pos_ts.y = -150;
    defender->pos_ts2.x = 530;
    defender->pos_ts2.y = 0;
    defender->pos_ts3.x = 520;
    defender->pos_ts3.y = 230;
    defender->pos_ts4.x = 200;
    defender->pos_ts4.y = 280;
    defender->pos_ts5.x = 845;
    defender->pos_ts5.y = 180;
    defender->pos_ts6.x = 1180;
    defender->pos_ts6.y = 30;
    defender->pos_ts7.x = 845;
    defender->pos_ts7.y = 430;
    defender->pos_sws.x = 265;
    defender->pos_sws.y = 130;
    defender->pos_sws2.x = 595;
    position9(defender);
}