#pragma once
#define TINYOBJLOADER_IMPLEMENTATION
#include <string>
#include <vector>
#include <array>
#include "log.h"
#include "tiny_obj_loader.h"


namespace sge {
	namespace Utility {
		const float OGLCreateObjFromFile(std::string path) {
			tinyobj::attrib_t objAtrribute;
			std::string warnings, errors;
			std::vector<tinyobj::material_t> materials;
			std::vector<tinyobj::shape_t> shapes;
			bool loadObj = tinyobj::LoadObj(&objAtrribute, &shapes,&materials, &warnings, &errors, path.c_str());
			if (loadObj) {
				if (!warnings.empty()) {
					LOG("Tiny obj loader warning");
					LOG(warnings);
				}
				if (!errors.empty()) {
					LOG("Tiny obj loader error");
					LOG(errors);
				}
				std::vector<tinyobj::real_t> modelData;
				for (int i = 0; i < shapes.size(); i++) {
					modelData.push_back(objAtrribute.vertices[i]);
					LOG(i);
				}
				system("PAUSE");
				LOG(modelData[0]);
				LOG(modelData[1]);
				LOG(modelData[2]);

				return NULL;
			}
			else LOG("Obj loading failed");
			return NULL;
		}
	}

}
