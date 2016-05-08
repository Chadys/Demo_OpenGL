#include "game_object.h"


Object2D::Object2D(Texture2D sprite, GLuint width, GLuint height)
    : GameObject(sprite), Position(0), Size(glm::vec2(width,height)), Velocity(0), Reversed(GL_FALSE), Action(IDLE), N_img(0), Sprite_size(1) {
        std::vector<GLuint> n_max;
        n_max.push_back(1);
        this->N_max=n_max;
    }

Object2D::Object2D(Texture2D sprite, glm::vec2 position)
    : GameObject(sprite), Position(position), Velocity(0), Reversed(GL_FALSE), Action(IDLE), N_img(0), Sprite_size(1) {
        this->Size = glm::vec2(this->Tex.Width, this->Tex.Height);
        std::vector<GLuint> n_max;
        n_max.push_back(1);
        this->N_max=n_max;
    }

Object2D::Object2D(Texture2D sprite, std::vector<GLuint> n_max)
    : GameObject(sprite), Position(0), Velocity(0), Reversed(GL_FALSE), Action(IDLE), N_img(0), N_max(n_max) {
        GLuint max = 1;
        for (GLuint n : this->N_max)
            max = n > max ? n : max;
        this->Size=glm::vec2(sprite.Width/max,sprite.Height/this->N_max.size());
        this->Sprite_size.x=1.0f/max;
        this->Sprite_size.y=1.0f/this->N_max.size();
    }

void Object2D::Draw(SpriteRenderer &renderer, glm::mat4 projection, glm::mat4 view)
{
    renderer.DrawSprite(this->Tex, this->Position, this->Size, projection, view, this->Reversed, this->Action, this->N_img, this->Sprite_size);
}