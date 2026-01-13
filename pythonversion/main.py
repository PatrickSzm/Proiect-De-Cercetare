import pygame
pygame.init()
screen = pygame.display.set_mode((400, 300))
clock = pygame.time.Clock()
x, y = 200, 150
dx, dy = 3, 3

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    x += dx
    y += dy
    if x < 0 or x > 400: dx = -dx
    if y < 0 or y > 300: dy = -dy

    screen.fill((0,0,0))
    pygame.draw.circle(screen, (255,0,0), (x,y), 20)
    pygame.display.flip()
    clock.tick(60)
    fps = int(clock.get_fps())
    fps_text = font.render(f"FPS: {fps}", True, (255,255,255))
    screen.blit(fps_text, (10,10))

pygame.quit()
