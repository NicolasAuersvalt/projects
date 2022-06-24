import pygame
import settings

class Ship:
    def __init__(self, screen, ai_settings):
        self.screen = screen
        self.screen_rect = self.screen.get_rect
        self.ai_settings = ai_settings
        self.image = settings.Settings().imagem
        self.bg = settings.Settings().bg
        self.bg_rect = self.bg.get_rect()
        # pygame.rect -> Indica as coordenadas do objeto (x, y), rect = retângulos
        self.rect = self.image.get_rect()
        self.screen_rect = screen.get_rect()
        self.rect.centerx = self.screen_rect.centerx # -> Centro do eixo x
        self.rect.centery = self.screen_rect.centery
        self.rect.bottom = self.screen_rect.bottom
        self.centerx = float(self.rect.centerx)
        self.centery = float(self.rect.centery)
        self.moving_right = False
        self.moving_left = False
        self.moving_up = False
        self.moving_down = False


    def update(self):
        if self.moving_right and self.rect.right < self.screen_rect.right:
            self.centerx += self.ai_settings.ship_speed
            self.rect.centerx = self.centerx
        if self.moving_left and self.rect.left > 0:
            self.centerx -= self.ai_settings.ship_speed
            self.rect.centerx = self.centerx
        if self.moving_up and self.rect.top > 0:
            self.centery -= self.ai_settings.ship_speed
            self.rect.centery = self.centery
        if self.moving_down and self.rect.bottom < self.screen_rect.bottom :
            self.centery += self.ai_settings.ship_speed
            self.rect.centery = self.centery

    def blitme(self):
        self.screen.blit(self.image, self.rect)

