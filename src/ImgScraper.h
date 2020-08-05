#pragma once
#include "SecureNetwork.h"
#include <vector>
std::vector<std::string> GetAllImgURLs(std::string URL);
bool DownloadImgFromURL(std::string URL, std::string Directory);
bool DownloadAllImagesOnPage(std::string URL, std::string Directory);