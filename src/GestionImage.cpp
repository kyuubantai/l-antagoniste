#include "GestionImage.h"
#include <iostream>

using namespace std;


GestionImage::GestionImage()
{
    m_surface = nullptr;
    m_texture = nullptr;
    m_hasChanged = false;
}

GestionImage::~GestionImage()
{
    cout<<"GestionImage::~GestionImage"<<endl;
    free();
}

void GestionImage::free()
{
    cout<<"GestionImage::free"<<endl;
    if (m_texture != nullptr)
    {
        cout<<"ERREUR DE TEXTURE"<<endl;
        m_texture = nullptr;
    }
    if (m_surface != nullptr)
    {
        SDL_FreeSurface(m_surface);
        m_surface = nullptr;
    }

    m_hasChanged = false;
}


void GestionImage::loadFile(const char *filename, SDL_Renderer *renderer)
{
    m_surface = IMG_Load(filename);
    if (m_surface == nullptr)
    {
        cout << "Erreur lors du chargement de l'image" << endl << SDL_GetError() << endl;
        SDL_Quit();
    }
    cout<<"texture avant create : "<<m_texture<<endl;
    m_texture = SDL_CreateTextureFromSurface(renderer, m_surface);
    cout<<"texture après create : "<<m_texture<<endl;
    //SDL_FreeSurface(m_surface);
    //m_surface = nullptr;
    //cout<<"surface : "<< m_surface<<endl;
    if (m_texture == nullptr)
    {
        cout << "Error: problem to create the texture of " << filename << endl;
        SDL_Quit();
    }
    SDL_FreeSurface(m_surface);
}

void GestionImage::loadMap(SDL_Renderer *renderer, int nCarte)
{
    if (nCarte == 0)
        loadFile("data/Map0.png", renderer);
    if (nCarte == 1)
        loadFile("data/Map1.png", renderer);
    if (nCarte == 2)
        loadFile("data/Map2.png", renderer);
    if (nCarte == 3)
        loadFile("data/Map3.png", renderer);
    if (nCarte == 4)
        loadFile("data/Map4.png", renderer);
    if (nCarte == 5)
        loadFile("data/Map5.png", renderer);
    if (nCarte == 6)
        loadFile("data/Map6.png", renderer);
    if (nCarte == 7)
        loadFile("data/Map7.png", renderer);
    if (nCarte == 8) 
        loadFile("data/Map8.png", renderer);
    if (nCarte == 9)
        loadFile("data/Map9.png", renderer);
    if (nCarte == 10)
        loadFile("data/Map10.png", renderer);
    if (nCarte == 11)
        loadFile("data/Map11.png", renderer);
}
void GestionImage::loadPerso(SDL_Renderer * renderer,char sprite_perso) {
    switch (sprite_perso) 
    {
        case 'g':
            m_surface = IMG_Load("data/perso.png");
            break;
        case 'd':
            m_surface = IMG_Load("data/perso.png");
            break;
        case 'h':
            m_surface = IMG_Load("data/perso.png");
            break;
        case 'b':
            m_surface = IMG_Load("data/perso.png");
            break;
        default :
            m_surface = IMG_Load("data/perso.png");
            break;
    }
    if(m_surface == nullptr) {  
        cout << "Erreur lors du chargement du personnage"<<endl<<SDL_GetError()<<endl;
        SDL_Quit();
        exit(1);
    }
    SDL_FreeSurface(m_surface);
    m_texture = SDL_CreateTextureFromSurface(renderer,m_surface);
    if (m_texture == nullptr) {
        cout << "Error: problème lors de la création de la texture " << endl;
        SDL_Quit();
        exit(1);
    }
}

void GestionImage::draw(SDL_Renderer *renderer, int x, int y, int w = -1, int h = -1)
{
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    pos.w = (w < 0) ? m_surface->w : w;
    pos.h = (h < 0) ? m_surface->h : h;
    if (m_hasChanged)
    {
        SDL_UpdateTexture(m_texture, nullptr, m_surface->pixels, m_surface->pitch);
        m_hasChanged = false;
    }
    SDL_RenderCopy(renderer, m_texture, nullptr, &pos);
}


void GestionImage::creerDial(SDL_Renderer *renderer,int num_pnj,int num_dial) {
    
}


