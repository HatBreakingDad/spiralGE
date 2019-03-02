#pragma once
#include <string>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "BasicModel.h"
#include "log.h"
namespace sge {
	namespace Utility {
		sge::Graph::BasicModel createModelFromFile(std::string path) {
			Assimp::Importer assimpImport;
			const aiScene* assimpScene = assimpImport.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);
			sge::Graph::BasicModel model;
			if (!assimpScene) {
				LOG("Assimp scene scene loading has failed");
			}
			else {
				model.meshes.reserve(assimpScene->mNumMeshes);
				for (int i = 0; assimpScene->mNumMeshes > i; i++) {
					sge::Graph::BasicMesh curMesh;
					for (int j = 0; assimpScene->mMeshes[i]->mNumFaces > j; j++)
						for(int k =0; assimpScene->mMeshes[i]->mFaces->mNumIndices > k; k++)
							curMesh.indices.push_back(assimpScene->mMeshes[i]->mFaces[j].mIndices[k]);
					for (int l = 0; assimpScene->mMeshes[i]->mNumVertices > l; l++) {
						curMesh.vertices.push_back(assimpScene->mMeshes[i]->mVertices[l].x);
						curMesh.vertices.push_back(assimpScene->mMeshes[i]->mVertices[l].y);
						curMesh.vertices.push_back(assimpScene->mMeshes[i]->mVertices[l].z);
					}
					model.meshes.push_back(curMesh);
				}
			}
			return model;
		}
	}

}
