#ifndef SWARM_SCREEN_H
#define SWARM_SCREEN_H

#include <SDL.h>

namespace swarm
{

class Screen
{
public:
    const static int SCREEN_WIDTH;
    const static int SCREEN_HEIGHT;

private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    Uint32 *m_bufferPrimary;
    Uint32 *m_bufferSecondary;  /* Need two buffers for box blur algorithm */

public:
    Screen();
    bool init();
    void update();
    void clear();
    void close();
    bool processEvents();
    void setPixel(unsigned int x, unsigned int y, Uint8 r, Uint8 g, Uint8 b);
    void boxBlur();
};

} /* namespace swarm */

#endif /* SWARM_SCREEN_H */