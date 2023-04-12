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
        // return new EstadoCamaraLock(*cam.get_obj_lock());
    }

    return new EstadoCamaraMover({0,0});
};

void EstadoCamaraMover::on_entrar(Camara &cam)
{
    cam.set_posicion_mundo({cam.get_posicion_mundo().x + (int)(direccion.x * cam.velocidad), cam.get_posicion_mundo().y + (int)(direccion.y * cam.velocidad)});
    cam.set_posicion_centro({cam.get_posicion_centro().x + (int)(direccion.x * cam.velocidad), cam.get_posicion_centro().y + (int)(direccion.y * cam.velocidad)});

};
void EstadoCamaraMover::on_salir(Camara &cam)
{
    cam.set_posicion_mundo({0,0});
};
void EstadoCamaraMover::on_update(Camara &cam)
{

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
    

    if (u>=1)
    {
        std::cout << "Ya llego" << std::endl;
        return new EstadoCamaraLock(*cam.get_obj_lock());
    }
 

    return NULL;
};

void EstadoCamaraTransicion::on_entrar(Camara &cam)
{
    check = {cam.get_posicion_mundo().x+cam.get_width()/2, cam.get_posicion_mundo().y+cam.get_height()/2};
    ant_check = {cam.get_obj_lock()->get_posicion_mundo().x - cam.get_width()/2, cam.get_obj_lock()->get_posicion_mundo().y - cam.get_height()/2};
    u = 0;
};
void EstadoCamaraTransicion::on_salir(Camara &cam)
{
    //Hay que implementar
};
void EstadoCamaraTransicion::on_update(Camara &cam)
{
    check = {cam.get_obj_lock()->get_posicion_mundo().x - cam.get_width()/2, cam.get_obj_lock()->get_posicion_mundo().y - cam.get_height()/2};
    Coordenadas pix = LERP(ant_check,check,u);
    cam.set_posicion_mundo(pix);
    u+=diff;

    std::cout << "Coordenadas: " << pix.x << " " << pix.y << std::endl;
    std::cout << "Destino: " << check.x << " " << check.y << std::endl;
    std::cout << "u: " << u << std::endl;
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
    if (keys.estaPresionado(SDL_SCANCODE_U))
    {
        return new EstadoCamaraMover({0,0});
    }

    return NULL;
};

void EstadoCamaraLock::on_entrar(Camara &cam)
{
    cam.lock_objeto(*obj);

    
};
void EstadoCamaraLock::on_salir(Camara &cam)
{
    //Hay que implementar
};
void EstadoCamaraLock::on_update(Camara &cam)
{
    cam.set_posicion_mundo({obj->get_posicion_mundo().x - cam.get_width()/2, obj->get_posicion_mundo().y - cam.get_height()/2});
};