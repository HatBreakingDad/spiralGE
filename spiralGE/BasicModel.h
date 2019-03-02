#pragma once
#include "BasicMesh.h"
namespace sge {
	namespace Graph {
		class BasicModel
		{
		public:
			std::vector<BasicMesh> meshes;
			BasicModel();
			~BasicModel();
		};
	}


}
