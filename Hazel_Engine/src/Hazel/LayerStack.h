#pragma once

#include "Layer.h"

namespace Hazel {

	class HAZEL_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlayer(Layer* layer);
		void PopLayer(Layer* layer);
		void PopOverlayer(Layer* layer);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }
	private:
		std::vector<Layer*> m_Layers;	// Layers µÄ°ü×°
		std::vector<Layer*>::iterator m_LayersInsert;
	};

}