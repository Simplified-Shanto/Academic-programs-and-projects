import pygame
import os
from random import randint
# https://www.youtube.com/watch?v=8OMghdHP-zs&t=14s
os.chdir('D:\[03] Codes\[08] Python codes\[01] Pygame projects\[03] Space Shooter game')


#general setup
pygame.init()
WINDOW_WIDTH, WINDOW_HEIGHT = 1280, 720
display_surface = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))
pygame.display.set_caption("Space Shooter")
running = True


# surface
surf = pygame.Surface((100, 200))
surf.fill('blue')

#import an image
#player_surf = pygame.image.load('D:\[03] Codes\[08] Python codes\[01] Pygame projects\[03] Space Shooter game/images/laser.png')
player_surf = pygame.image.load('images/player.png').convert_alpha()
player_rect = player_surf.get_rect(bottomleft = (WINDOW_WIDTH - 10, WINDOW_HEIGHT - 10))

star_surf = pygame.image.load('images/star.png').convert_alpha()
star_positions = [(randint(0, WINDOW_WIDTH), randint(0, WINDOW_HEIGHT)) for i in range(20)]



meteor_surf = pygame.image.load('images/meteor.png').convert_alpha()
meteor_rect = meteor_surf.get_rect(center = (WINDOW_WIDTH/2, WINDOW_HEIGHT/2))

laser_surf = pygame.image.load('images/laser.png').convert_alpha()
laser_rect = laser_surf.get_rect(bottomleft = (WINDOW_WIDTH - 20, WINDOW_HEIGHT - 20))



while running:
    # event loop
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    # draw the game
    display_surface.fill('darkgray')
    display_surface.blit(player_surf, (100, 100))
    display_surface.blit(meteor_surf, meteor_rect)
    display_surface.blit(laser_surf, laser_rect)

    

    if player_rect.right < WINDOW_WIDTH:
        print("matched")
    
    for i in range(20):
        display_surface.blit(star_surf, star_positions[i])
    pygame.display.update()