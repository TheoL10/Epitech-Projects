#!/usr/bin/env python3
# -*- coding: utf-8 -*-
##
## EPITECH PROJECT, 2019
## 101pong.py
## File description:
## 101pong.py
##

import pygame
import time

pygame.init()
root = pygame.display.set_mode((1250, 720))
pygame.display.set_caption("101pong")

police = pygame.font.Font("ARCADE.TTF",72)
player1 = [50, 250]
player2 = [1150, 250]
ball = [625, 360]
run = True
vect_ball = [1, 1]
score = [0, 0]

def hit_p1(player1):
    if player1[1] < 0:
        return (2)
    elif player1[1] > 520:
        return (-2)
    else:
        return (0)
    
def hit_p2(player2):
    if player2[1] < 0:
        return (2)
    elif player2[1] > 520:
        return (-2)
    else: 
        return (0)
        
def res():
    ball[0] = 625
    ball[1] = 360
    root.fill((0,0,0))
    texte_p1 = police.render(str(score[0]), True, pygame.Color("#FFFFFF"))
    texte_p2 = police.render(str(score[1]), True, pygame.Color("#FFFFFF"))
    pygame.draw.rect(root, (250,250,250), (ball[0], ball[1], 30, 30))
    pygame.draw.rect(root, (250,250,250), (player1[0], player1[1], 30, 200))
    pygame.draw.rect(root, (250,250,250), (player2[0], player2[1], 30, 200))
    textRect_p1 = texte_p1.get_rect()
    textRect_p1.center = (500, 100)
    root.blit(texte_p1, textRect_p1)
    textRect_p2 = texte_p2.get_rect()
    textRect_p2.center = (770, 100)
    root.blit(texte_p2, textRect_p2)
    pygame.display.update()
    
def hit_ball(ball, vect_ball):
    if ball[0] < 80 and ball[1] > player1[1] and ball[1] < player1[1] + 200:
        vect_ball[0] = -vect_ball[0]
    elif ball[0] > 1120 and ball[1] > player2[1] and ball[1] < player2[1] + 200:
        vect_ball[0] = -vect_ball[0]
    if ball[0] < 50:
        vect_ball[0] = -vect_ball[0]
        score[1] += 1
        ball = [625, 360]
        res()
        time.sleep(2)
    elif ball[0] > 1150:
        vect_ball[0] = -vect_ball[0]
        score[0] += 1
        res()
        time.sleep(2)
    if ball[1] < 0 or ball[1] > 705:
        vect_ball[1] = -vect_ball[1]

while run:
    pygame.key.set_repeat(400,15)
    
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            run = False
    
    keys = pygame.key.get_pressed()
    
    hit_ball(ball, vect_ball)
    
    ball[0] = ball[0] + vect_ball[0]
    ball[1] = ball[1] + vect_ball[1]
    
    if keys[pygame.K_UP]:
        player2[1] -= 2 - hit_p2(player2)
    elif keys[pygame.K_DOWN]:
        player2[1] += 2 + hit_p2(player2)
    if keys[pygame.K_z]:
        player1[1] -= 2 - hit_p1(player1) 
    elif keys[pygame.K_s]:
        player1[1] += 2 + hit_p1(player1)
        
    root.fill((0,0,0))
    texte_p1 = police.render(str(score[0]), True, pygame.Color("#FFFFFF"))
    texte_p2 = police.render(str(score[1]), True, pygame.Color("#FFFFFF"))
    pygame.draw.rect(root, (250,250,250), (ball[0], ball[1], 30, 30))
    pygame.draw.rect(root, (250,250,250), (player1[0], player1[1], 30, 200))
    pygame.draw.rect(root, (250,250,250), (player2[0], player2[1], 30, 200))
    textRect_p1 = texte_p1.get_rect()
    textRect_p1.center = (500, 100)
    root.blit(texte_p1, textRect_p1)
    textRect_p2 = texte_p2.get_rect()
    textRect_p2.center = (770, 100)
    root.blit(texte_p2, textRect_p2)
    pygame.display.update()

pygame.quit()