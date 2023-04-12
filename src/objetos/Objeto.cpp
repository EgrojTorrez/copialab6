#include "Objeto.hpp"
#include "../motor/Pipeline.hpp"

void Objeto::render(SDL_Renderer* r)
{

    Pipeline temp(*r);
    temp.figuras(avatar);
    if(render_colbox)
        temp.figuras(col_box);
};

void Objeto::set_posicion_camara(Coordenadas p)
{
    posicion_camara = p;
};

void Objeto::set_posicion_mundo(Coordenadas p)
{
    posicion_mundo =p;
    avatar->set_position(p.x,p.y);
    avatar->update_vertices();
    col_box->set_position(p.x,p.y);
    col_box->update_vertices();
};
void Objeto::set_posx(int x)
{
    posicion_mundo.x=x;
    avatar->set_position(posicion_mundo.x,posicion_mundo.y);
    avatar->update_vertices();
    col_box->set_position(posicion_mundo.x,posicion_mundo.y);
    col_box->update_vertices();
};
void Objeto::set_posy(int y)
{
    posicion_mundo.y=y;
    avatar->set_position(posicion_mundo.x,posicion_mundo.y);
    avatar->update_vertices();
    col_box->set_position(posicion_mundo.x,posicion_mundo.y);
    col_box->update_vertices();
};