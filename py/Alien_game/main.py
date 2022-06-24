"""
Invasão Alienígena

Propostas: Antes de sair, salvar progresso
"""
import sys
import pygame
from ship import *
from settings import *
from song import Musicas
from game_functions import *
from bullet import *
from pygame.sprite import Group

musica_tocando = 0



def run():
    """
    Para todo <py.game>, nós teremos uma relação de funções

    .diplay - Vamos trabalhar com a Janela
    .init() - Iniciaremos o programa

    :return:
    """

    global musica_tocando
    pygame.init()
    ai_settings = Settings()
    screen = pygame.display.set_mode((Settings().screen_x,
                                      Settings().screen_y))  # Define a escala da Janela, Settings().screenx -> Vem de settings.py
    pygame.display.set_caption("Alien")  # Define o Título
    ship = Ship(screen, ai_settings)
    bullets = Group()

    if musica_tocando == 0:
        pygame.mixer.music.load(Musicas().level1)
        pygame.mixer.music.play()
        musica_tocando = 1
    while True:  # Inicia o laço principal do jogo
        check_events(ai_settings, screen, ship, bullets)
        bullets.update()
        ship.update()
        update_bullets(bullets)
        update_screen(ai_settings, screen, ship, bullets)


run()
