"""
Alienígenas

"""

from pygame.sprite import Sprite
from settings import Settings

class Alien(Sprite):
    """ Uma classe que representa um único alien """

    def __init__(self, ai_settings, screen):
        super().__init__()
        self.screen = screen 
        self.ai_settings = ai_settings

        # Carrega a Imagem do Alien 
        self.blue_alien = Settings().blue_alien
        self.rect = self.blue_alien.get_rect()

        # Inicia cada alien próximo ao canto esquerdo superior

        self.rect.x = self.rect.width 
        self.rect.y = self.rect.height

        # Armazena a posição do alien

        self.x = float(self.rect.x)

    def blitme(self):
        """ Desenha o Alien em sua posição """
        self.screen.blit(self.blue_alien, self.rect)