#pragma once
#include "Canvas.h"
#include "../Math/Ray.h"
#include "../Object/Object.h"
#include <SDL.h>

class Renderer
{
public:
	Renderer() = default;

	bool Initialize();
	void Shutdown();

	void Render(Canvas& canvas, Object* object);

	bool CreateWindow(int width, int height);

	void CopyCanvas(const Canvas& canvas);
	void Present();

	friend class Canvas;

private:
	SDL_Window* m_window{ nullptr };
	SDL_Renderer* m_renderer{ nullptr };

private:
	color3 GetBackgroundFromRay(const Ray& ray);
};