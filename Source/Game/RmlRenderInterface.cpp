#include "RmlRenderInterface.h"
#include <Engine/Render2D/RotatedRectangle.h>
#include <Engine/Core/Math/Half.h>


RmlRenderInterface::RmlRenderInterface()
{
}


void RmlRenderInterface::Init()
{
}

struct Flax2DVertex {
	Vector2 Position;
	Half2 TexCoord;
	Color Color;
	Vector2 CustomData;
	RotatedRectangle ClipMask;
};

void RmlRenderInterface::RenderGeometry(Rml::Core::Vertex* vertices, int num_vertices, int* indices, int num_indices, Rml::Core::TextureHandle texture, const Rml::Core::Vector2f& translation)
{
	Array<Flax2DVertex> lVertices;

	for (int i = 0; i < num_vertices; i++) {
		lVertices.Add(Flax2DVertex{
			Vector2(vertices[i].position.x,vertices[i].position.y),
			Half2(vertices[i].tex_coord.x,vertices[i].tex_coord.y),
			Color(vertices[i].colour.red,vertices[i].colour.green,vertices[i].colour.blue,vertices[i].colour.alpha),
			{ 0.0f, (float)Render2D::Features }
			});
	}

	Array<uint32> lIndices;

	for (int i = 0; i < num_indices; i++) {
		lIndices.Add(indices[i]);
	}

	Render2D::DrawCustomVertices(lVertices.Get(),num_vertices,lIndices.Get(),num_indices);

}

Rml::Core::CompiledGeometryHandle RmlRenderInterface::CompileGeometry(Rml::Core::Vertex* vertices, int num_vertices, int* indices, int num_indices, Rml::Core::TextureHandle texture)
{
	return Rml::Core::CompiledGeometryHandle();
}

void RmlRenderInterface::RenderCompiledGeometry(Rml::Core::CompiledGeometryHandle geometry, const Rml::Core::Vector2f& translation)
{
}

void RmlRenderInterface::ReleaseCompiledGeometry(Rml::Core::CompiledGeometryHandle geometry)
{
}

void RmlRenderInterface::EnableScissorRegion(bool enable)
{
}

void RmlRenderInterface::SetScissorRegion(int x, int y, int width, int height)
{
}

bool RmlRenderInterface::LoadTexture(Rml::Core::TextureHandle& texture_handle, Rml::Core::Vector2i& texture_dimensions, const Rml::Core::String& source)
{
	return false;
}

bool RmlRenderInterface::GenerateTexture(Rml::Core::TextureHandle& texture_handle, const Rml::Core::byte* source, const Rml::Core::Vector2i& source_dimensions)
{
	return false;
}

void RmlRenderInterface::ReleaseTexture(Rml::Core::TextureHandle texture_handle)
{
}

