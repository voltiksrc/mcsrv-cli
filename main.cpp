#include <curl/curl.h>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

using std::string;
using json = nlohmann::json;

// data writing function
size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
  size_t total = size * nmemb;

  std::string *response = static_cast<std::string *>(userdata);

  response->append(ptr, total);

  return total;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Please enter a server address.\n";
    return 1;
  }
  string server = argv[1];
  auto apiurl = "https://api.mcsrvstat.us/3/" + server;
  string response;
  CURL *curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, apiurl.c_str());

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

    curl_easy_setopt(curl, CURLOPT_USERAGENT, "mcsrv-cli/0.1");

    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
  }
  CURLcode result = curl_easy_perform(curl);
  long response_code;
  json data = json::parse(response);
  result = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
  if (result != CURLE_OK) {
    std::cerr << curl_easy_strerror(result) << '\n';
    return 1;
  }
  if (data["online"] == false) {
      std::cerr<<"Server appears offline or could not be reached.\n";
      return 1;
  }
    std::string hostname = data["hostname"].get<std::string>();
    std::string ip = data["ip"].get<std::string>();
    std::string version = data["version"].get<std::string>();
    int port = data["port"].get<int>();
    string protocol = data["protocol"]["name"].get<string>();
    std::cout << "Server: "<<hostname<<'\n';
    std::cout << "Online: "<< data["online"] << '\n';
    std::cout << "IP: "<<ip<<'\n';
    std::cout << "Port: "<<port<<'\n';
    std::cout << "Version: "<<version << '\n';
    std::cout << "Protocol: "<<protocol<<'\n';
    std::cout << "Players online: "<<data["players"]["online"] << " / " << data["players"]["max"]<<'\n';
    curl_easy_cleanup(curl);
}
