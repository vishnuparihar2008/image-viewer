#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *in = stdin;
  char *psthroway = calloc(1000, sizeof(char));
  fgets(psthroway, 1000, in); // Specifier (P3/P6) (ignore)
  fgets(psthroway, 1000, in); // Comment (ignore)
  char *psdimensions = calloc(1000, sizeof(char));
  fgets(psdimensions, 1000, in); // Dimensions (H/W) 
  fgets(psthroway, 1000, in);    // Maximum Colour Value (ignore)
  free(psthroway);

  int width;
  int height;
  sscanf(psdimensions, "%d %d\n", &width, &height);
  free(psdimensions);

  SDL_Window *pwindow =
      SDL_CreateWindow("Image Viewer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
  SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);

  SDL_Rect pixel = (SDL_Rect){0, 0, 1, 1};
  Uint8 r, g, b;
  Uint32 color = 0;
  for (int y = 0; y < height; y++)
  {
    for (int x = 0; x < width; x++)
    {
      r = (char) getchar();
      g = (char) getchar();
      b = (char) getchar();
      color = SDL_MapRGB(psurface->format,r,g,b);
      pixel.x = x;
      pixel.y = y;
      SDL_FillRect(psurface, &pixel, color);
    }
  }
  SDL_UpdateWindowSurface(pwindow);
  
  int app_running = 1;
  while (app_running)
  {
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
      {
        app_running = 0;
      }
      
    }
    SDL_Delay(100);
  }
  
  return 0;
}
