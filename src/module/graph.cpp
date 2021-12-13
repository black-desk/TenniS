//
// Created by kier on 2018/10/15.
//

#include "module/graph.h"

#include <module/graph.h>

#include <unordered_set>

#include "utils/ctxmgr_lite_support.h"

namespace ts
{
  static inline void plot_node(
    std::ostream &stream, const Node &node, std::unordered_set<Node> &plot) {
    {
      auto plot_it = plot.find(node);
      if (plot_it != plot.end()) return;
    }

    std::ostringstream oss;
    oss << node->op() << ": [" << node->name() << "] <== ";
    bool first = true;
    for (auto &input: node.inputs()) {
      if (first) {
        first = false;
      } else {
        oss << ", ";
      }
      oss << "[" << input->name() << "]";
    }
    oss << std::endl;
    stream << oss.str();

    plot.insert(node);
  }

  static inline void plot_graph(
    std::ostream             &stream,
    const std::vector<Node>  &nodes,
    std::unordered_set<Node> &plot) {
    for (auto &node: nodes) { plot_graph(stream, node.inputs(), plot); }
    for (auto &node: nodes) { plot_node(stream, node, plot); }
  }

  std::ostream &plot_graph(
    std::ostream &stream, const std::vector<Node> &nodes) {
    std::unordered_set<Node> plot;
    plot_graph(stream, nodes, plot);
    return stream;
  }
}  // namespace ts

TS_LITE_CONTEXT(ts::Graph)
