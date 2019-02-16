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
			std::vector<tinyobj::shape_t> shapes;
			bool loadObj = tinyobj::LoadObj(&objAtrribute, &shapes, nullptr, &warnings, &errors,
				path.c_str());
			if (loadObj) {
				
				if (!warnings.empty()) {
					LOG("Tiny obj loader warning");
					LOG(warnings);
				}
				if (!errors.empty()) {
					LOG("Tiny obj loader error");
					LOG(errors);
					for (int i = 0; i < shapes.size(); i++) {
						std::vector<tinyobj::real_t> data;
						data.append(objAtrribute.vertices[i]);
					}
				}
			}
			else LOG("Obj loading failed");
			return NULL;
		}
	}

}
