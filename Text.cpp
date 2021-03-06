#include "text.h"

Text::Text(std::string t, glm::vec2 position, GLfloat size_factor, glm::vec3 color)
	: text(t), Position(position), Size_factor(size_factor), Color(color){ }
	
void Text::Draw(StateManager &manager, TextRenderer &renderer){
	renderer.RenderText(manager, this->text, this->Position.x, this->Position.y, this->Size_factor, this->Color);
}