#include "FSMCamaras.hpp"
#include "../Func_aux.hpp"
#include <iostream>

EstadoCamaraMover::EstadoCamaraMover(Coordenadas dir)
{
    direccion = dir;
    strestado = "mover";
};

FSMCamara* EstadoCamaraMover::input_handle(Camara &cam, KeyOyente &keys, MouseOyente& mouse)
{
    if(keys.estaPresionado(SDL_SCANCODE_RIGHT) && keys.estaPresionado(SDL_SCANCODE_UP))
    {
        return new EstadoCamaraMover({1,-1});
    }
    if(keys.estaPresionado(SDL_SCANCODE_RIGHT) && keys.estaPresionado(SDL_SCANCODE_DOWN))
    {
        return new EstadoCamaraMover({1,1});
    }
    if(keys.estaPresionado(SDL_SCANCODE_LEFT) && keys.estaPresionado(SDL_SCANCODE_UP))
    {
        return new EstadoCamaraMover({-1,-1});
    }
    if(keys.estaPresionado(SDL_SCANCODE_LEFT) && keys.estaPresionado(SDL_SCANCODE_DOWN))
    {
        return new EstadoCamaraMover({-1,1});
    }
    if(keys.estaPresionado(SDL_SCANCODE_UP))
    {
        return new EstadoCamaraMover({0,-1});
    }
    if(keys.estaPresionado(SDL_SCANCODE_DOWN))
    {
        return new EstadoCamaraMover({0,1});
    }
    if(keys.estaPresionado(SDL_SCANCODE_LEFT))
    {
        return new EstadoCamaraMover({-1,0});
    }
    if(keys.estaPresionado(SDL_SCANCODE_RIGHT))
    {
        return new EstadoCamaraMover({1,0});
    }

    if(keys.estaPresionado(SDL_SCANCODE_L))
    {
        return new EstadoCamaraTransicion();
    }

    return new EstadoCamaraMover({0,0});
};

void EstadoCamaraMover::on_entrar(Camara &cam)
{
    //Hay que implementar

};
void EstadoCamaraMover::on_salir(Camara &cam)
{
    //Hay que implementar
};
void EstadoCamaraMover::on_update(Camara &cam)
{
    //Hay que implementar
};

/*
TRANSICIÓN
*/
EstadoCamaraTransicion::EstadoCamaraTransicion()
{
    frames_actual =0;
    frames_maximo = 45;
    strestado = "transicion";
};

FSMCamara* EstadoCamaraTransicion::input_handle(Camara &cam, KeyOyente &keys, MouseOyente& mouse)
{
    
    //Hay que implementar

    return NULL;
};

void EstadoCamaraTransicion::on_entrar(Camara &cam)
{
    //Hay que implementar
};
void EstadoCamaraTransicion::on_salir(Camara &cam)
{
    //Hay que implementar
};
void EstadoCamaraTransicion::on_update(Camara &cam)
{
    //Hay que implementar

};
/*
LOCK
*/
EstadoCamaraLock::EstadoCamaraLock(Objeto &objlock)
{
    strestado = "lock";
    obj = &objlock;

};

FSMCamara* EstadoCamaraLock::input_handle(Camara &cam, KeyOyente &keys, MouseOyente& mouse)
{
    
    //Hay que implementar

    return NULL;
};

void EstadoCamaraLock::on_entrar(Camara &cam)
{
    //Hay que implementar
    
};
void EstadoCamaraLock::on_salir(Camara &cam)
{
    //Hay que implementar
};
void EstadoCamaraLock::on_update(Camara &cam)
{
    //Hay que implementar

};