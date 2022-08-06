import pygame
from settings import Settings
from song import Musicas
from bullet import Bullet
from ship import Ship
from game_functions import *
from pygame.sprite import Group

musica_tocando = 0

<<<<<<< HEAD
=======

>>>>>>> 90df117cb6d64452c23c370739f17aa9de6af706
def run():

    global musica_tocando
    pygame.init()
    ai_settings = Settings()
    screen = pygame.display.set_mode((Settings().screen_x,
                                      Settings().screen_y))  # Define a escala da Janela, Settings().screenx -> Vem de settings.py
    pygame.display.set_caption('Alien')  # Define o Título
    ship = Ship(screen, ai_settings)
    bullets = Group()

    # Cria um alien

     # Frota de Alienígenas
    aliens = Group()
    fleet(ai_settings, screen, aliens)

    # Loop Musical
    if musica_tocando == 0:
        pygame.mixer.music.load(Musicas().level1)
        pygame.mixer.music.play()
        musica_tocando = 1

    while True:  # Inicia o laço principal do jogo
        check_events(ai_settings, screen, ship, bullets)
        bullets.update()
        ship.update()
        update_bullets(bullets)
        update_screen(ai_settings, screen, ship, aliens, bullets)

run()
