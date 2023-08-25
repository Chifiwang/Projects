# Python
import numpy as np
from numpy import linalg as LA
import networkx as nx
import matplotlib.pyplot as ppl
from scipy.sparse import csr_matrix
from scipy.sparse.csgraph import connected_components

g = np.array(
    [[0, 0, 0, 0, 6, 4, 0, 0, 0, 0], 
     [0, 0, 0, 4, 0, 0, 0, 2, 0, 0], 
     [0, 0, 0, 0, 5, 0, 0, 6, 0, 0], 
     [0, 4, 0, 0, 0, 0, 0, 0, 0, 6], 
     [6, 0, 5, 0, 0, 0, 0, 0, 0, 4], 
     [4, 0, 0, 0, 0, 0, 4, 0, 0, 6], 
     [0, 0, 0, 0, 0, 4, 0, 0, 0, 0], 
     [0, 2, 6, 0, 0, 0, 0, 0, 3, 0], 
     [0, 0, 0, 0, 0, 0, 0, 3, 0, 0], 
     [0, 0, 0, 6, 4, 6, 0, 0, 0, 0]]
)

def importance_signal(g, v):
    total = 0
    temp = 0
    for i in range(nx.number_of_nodes(g)):
        temp = nx.shortest_path_length(g, v, i, weight='weight')
        if(temp != 0):
            total += (1/temp)
    norm_factor = 1/total

    importance_signal = np.zeros(nx.number_of_nodes(g))
    for i in range(nx.number_of_nodes(g)):
        temp = nx.shortest_path_length(g, v, i, weight='weight')
        if(temp != 0):
            importance_signal[i] = (norm_factor/temp)
        else:
            importance_signal[i] = 1
    return importance_signal
    
def linked_sort(eigval, eigvec):
    eigval_sort = np.sort(eigval)
    temp = dict()
    for i in range(eigval.shape[0]):
        temp[i] = eigval.tolist().index(eigval_sort[i])
    # print(eigval_sort)
    eigvec_sort = [0]*eigval.shape[0]

    for i in range(eigval.shape[0]):
        eigvec_sort[i] = eigvec[temp[i]]

    # print(temp)
    return [np.array(eigval_sort), np.array(eigvec_sort)]


def graph_fourier_transform_dist(g, v, laplacian_eigvec):

    gft = np.zeros(laplacian_eigvec.shape[0])
    # # print(gft, "brh")
    for i in range(laplacian_eigvec.shape[0]):
        for j in range(nx.number_of_nodes(g)):
            gft[i] += (importance_signal(g, v)[j])*laplacian_eigvec.transpose()[i][j]
    #     # print(gft)
    return gft

def weight(eigval):
    return np.exp(0.1*eigval)-1

def graph_fourier_transform_centrality(g):
    n = nx.number_of_nodes(g) - 1

    laplacian_matrix = np.array(nx.laplacian_matrix(g, weight='weight').toarray())
    # print(laplacian_matrix)
    laplacian_eigval_and_vec_unsorted = LA.eig(laplacian_matrix)
    temp = linked_sort(laplacian_eigval_and_vec_unsorted[0], laplacian_eigval_and_vec_unsorted[1])
    laplacian_eigval = temp[0]
    laplacian_eigvec = temp[1]
    # print(type(laplacian_eigval))
    #GFT
    # importance_signal(g, 0)
    # print(graph_fourier_transform_dist(g, 3, laplacian_eigvec))
    gftc = np.zeros(n+1)
    for i in range(n + 1):
        gft = graph_fourier_transform_dist(g, i, laplacian_eigvec)
        # print(gft, i)
        for i in range(laplacian_eigval.shape[0]):
            gftc[i] += weight(laplacian_eigval[i])*np.abs(gft[i])
        # print(gftc, "br")
    return dict(enumerate(gftc))




g = nx.from_numpy_array(g)
# print(dict(enumerate((nx.adjacency_matrix(g).toarray()))))
# print(graph_fourier_transform_centrality(g))



print(graph_fourier_transform_centrality(g))
print(nx.degree_centrality(g))
print(nx.eigenvector_centrality(g))
print(nx.betweenness_centrality(g))
print(nx.closeness_centrality(g))


nx.draw_planar(g, with_labels = True)
ppl.show()

