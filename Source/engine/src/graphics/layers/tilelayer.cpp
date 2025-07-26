#include <graphics/layers/tilelayer.h>


namespace mintern
{
namespace graphics
{

	
TileLayer::TileLayer(Shader* shader) 
    : Layer(new BatchRenderer2D(), shader, math::Mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, 0, 1))
{
	
}

//TileLayer::~TileLayer()
//{
//}


}  // namespace graphics
}  // namespace mintern