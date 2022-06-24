import sys
import unittest
import pygame

from Projeto_Game import bullet
from ship import *
from settings import *
from bullet import *


""" Pressionamento de teclas """
def key_down(event, ai_settings, screen, ship, bullets):
    if event.key == pygame.K_RIGHT:
        # Mova a espaçonave para a direita, ou seja, some o rect.centerx
        # ship.rect.centerx += 10
        ship.moving_right = True
    if event.key == pygame.K_LEFT:
        # Mova a espaçonave para a esqueda, ou seja, subtraia o rect.centerx
        # ship.rect.centerx -= 10
        ship.moving_left = True
    if event.key == pygame.K_DOWN:
         # Mova a nave para baixo, ou seja, subtraia rect.centery
        # ship.rect.centery += 10
        ship.moving_down = True
    if event.key == pygame.K_UP:
        # Mova a nave para cima, ou seja, some o rect.centery
        # ship.rect.centery -= 1
        ship.moving_up = True
    if event.key == pygame.K_SPACE:
        if len(bullets) <= Settings().bullets_allow:
            fire_bullets(ai_settings, screen, ship, bullets)




def key_up(event, ship):
    if event.key == pygame.K_RIGHT:
        ship.moving_right = False
    elif event.key == pygame.K_LEFT:
        ship.moving_left = False
    elif event.key == pygame.K_UP:
        ship.moving_up = False
    elif event.key == pygame.K_DOWN:
        ship.moving_down = False

def check_events(ai_settings, screen, ship, bullets):
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
        elif event.type == pygame.KEYDOWN:
            key_down(event, ai_settings, screen, ship, bullets)
        elif event.type == pygame.KEYUP:
            key_up(event, ship)




def update_screen(ai_settings, screen, ship, bullets): # Atualiza as imagens na tela e alterna para a nova tela.
    # Redesenha a tela a cada passagem pelo laço
    screen.blit(Settings().bg, (0, 0))
    for bullet in bullets.sprites():
        bullet.bullet_update()
        bullet.print_bullet()
    ship.blitme()

    pygame.display.flip()

def update_bullets(bullets):
    for bullet in bullets.copy():
        if bullet.rect.bottom <= 0:
            bullets.remove(bullet)

def fire_bullets(ai_settings, screen, ship, bullets):
    new_bullet = Bullet(ai_settings, screen, ship)
    bullets.add(new_bullet)
