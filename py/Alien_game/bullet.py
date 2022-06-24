import pygame
from pygame.sprite import Sprite
from settings import *
from pygame.sprite import Group


class Bullet(Sprite):
    def __init__(self, ai_settings, screen, ship):
        super().__init__()
        self.screen = screen
        self.screen_rect = screen.get_rect()
        self.bullet = Settings().bullet
        self.rect = self.bullet.get_rect()
        # pygame.Rect(0, 0, settings.bullet_width, settings.bullet_height)
        self.rect.centerx = ship.rect.centerx
        self.rect.top = ship.rect.top
        self.y = float(self.rect.y)
        self.speed_bullet = ai_settings.bullet_speed

    def bullet_update(self):
        self.y -= self.speed_bullet
        self.rect.y = self.y

    def print_bullet(self):
        self.screen.blit(self.bullet, self.rect)
