#include <iostream>
#include <utility>
#include <string.h>
#include <vector>

struct node_t {
    std::string             name;
    bool                    isBig;
    int                     visitedCount;
    std::vector<node_t>    links;
};

bool inIds(std::vector<std::string> ids, std::string item){
    for (int i = 0; i < ids.size(); i++){
        if (item == ids[i])
            return true;
    }
    return false;
}

std::vector<std::string> getIds(std::vector<std::pair<std::string, std::string> > p){
    std::vector<std::string>    ret;

    for (int i = 0; i < p.size(); i++){
        if (!inIds(ret, p[i].first)){
            ret.push_back(p[i].first);
        }
    }
    return ret;
}

std::vector<node_t> initNodes(std::vector<std::string> ids){
    std::vector<node_t> ret;
    node_t              node;

    for (int i = 0; i < ids.size(); i++){
        node.name = ids[i];
        node.isBig = (node.name[0] > 64 && node.name[0] < 91);
        node.visitedCount = 0;
        node.links.clear();
        ret.push_back(node);
    }
    return ret;
}

std::vector<node_t> linkNodes(std::vector<node_t> n, std::vector<std::pair<std::string, std::string> > p){
    std::vector<node_t>     ret;
    std::vector<node_t>    tmp;
    // node_t                  *node;

    ret = n;
    for (int i = 0; i < n.size(); i++){
        tmp.clear();
        for (int j = 0; j < p.size(); j++){
            if (p[j].first == n[i].name){
                for (int k = 0; k < n.size(); k++){
                    if (n[k].name == p[j].second){
                        tmp.push_back(n[k]);
                    }
                }
            }
        }
        ret[i].links = tmp;
    }
    return ret;
}

void printNodes(std::vector<node_t> n){
    int     j;

    for (int i = 0; i < n.size(); i++){
        std::cout << "Node " << n[i].name << ":" << std::endl;
        std::cout << "   * isBig: " << n[i].isBig << std::endl;
        std::cout << "   * visitedCount: " << n[i].visitedCount << std::endl;
        std::cout << "   * links: ";
        for (j = 0; j < n[i].links.size(); j++){
            std::cout << n[i].links[j].name << ", ";
        }
        std::cout << std::endl;
    }
}

void printPaths(std::vector<std::pair<std::string, std::string> > p){
    for (int i = 0; i < p.size(); i++){
        std::cout << p[i].first << " " << p[i].second << std::endl;
    }
}

void printCorrectPath(std::vector<std::string> p){
    for (int i = 0; i < p.size(); i++){
        std::cout << p[i] << ",";
    }
    std::cout << std::endl;
}

void printCorrectPaths(std::vector<std::vector<std::string> > p){
    for (int i = 0; i < p.size(); i++){
        printCorrectPath(p[i]);
    }
}

void printIds(std::vector<std::string> i){
    printCorrectPath(i);
}

void countPath(node_t n, int &count, std::vector<node_t> nodes){
    node_t              next;
    int                 index;
    std::vector<node_t> tmp;

    std::cout << n.name << " -> ";
    tmp = nodes;
    for (int i = 0; i < nodes.size(); i++){
        if (nodes[i].name == n.name){
            index = i;
        }
    }
    tmp[index].visitedCount++;
    if (tmp[index].name == std::string("end")){
        count++;
        tmp[index].visitedCount--;
        return;
    }
    for (int i = 0; i < tmp[index].links.size(); i++){
        for (int j = 0; j < nodes.size(); j++){
            if (nodes[j].name == tmp[index].links[i].name){
                next = tmp[j];
                break;
            }
        }
        // next = n.links[i];
        if (next.visitedCount && !next.isBig)
            continue;
        countPath(next, count, tmp);
    }
    tmp[index].visitedCount--;
    std::cout << std::endl;
}

int main(int argc, char const *argv[]) {
    std::vector<std::pair<std::string, std::string> >   paths;
    std::pair<std::string, std::string>     tmpPath;
    std::vector<std::string>    ids;
    std::vector<node_t>         nodes;
    std::string in;
    size_t      pos;
    int         count;

    while (std::cin >> in){
        pos = in.find("-");
        tmpPath.first = in.substr(0, pos);
        in.erase(0, pos+1);
        tmpPath.second = in;
        paths.push_back(tmpPath);
        if (tmpPath.first != std::string("start") && tmpPath.second != std::string("end"))
            paths.push_back(std::make_pair(tmpPath.second, tmpPath.first));
    }
    ids = getIds(paths);
    ids.push_back(std::string("end"));
    nodes = initNodes(ids);
    nodes = linkNodes(nodes, paths);
    printNodes(nodes);

    count = 0;
    for (int i = 0; i < nodes.size(); i++){
        if (nodes[i].name == std::string("start"))
            countPath(nodes[i], count, nodes);
    }
    std::cout << "Res: " << count << std::endl;
    return 0;
}
