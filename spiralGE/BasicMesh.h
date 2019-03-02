#pragma once
#include <vector>
namespace sge {
	namespace Graph {
		struct BasicMesh
		{
		public:
			std::vector<float> vertices;
			std::vector<int> indices;
			BasicMesh();
			~BasicMesh();
		};

	}
}

