import networkx as nx
import matplotlib.pyplot as plt

def leer_grafo_desde_archivo(nombre_archivo):
    nodos = []
    aristas_con_pesos = []
    nodos_p = []
    aristas_con_pesos_p = []

    with open(nombre_archivo, 'r') as file:
        for line in file:
            # Eliminar espacios en blanco al inicio y al final de la línea
            line = line.strip()
            if line:
                # Verificar si la línea contiene un nodo
                if line.count(" ") <= 1:
                    nodo, path = map(int, line.split())
                    if path == 0:
                        nodos.append(nodo)
                    else:
                        nodos_p.append(nodo)
                else:
                    # Separar los elementos de la línea y convertirlos a enteros
                    nodo1, nodo2, peso, path = map(int, line.split())
                    if path == 0:
                        aristas_con_pesos.append((nodo1, nodo2, peso))
                    else:
                        aristas_con_pesos_p.append((nodo1,nodo2,peso))

    return nodos, aristas_con_pesos, nodos_p, aristas_con_pesos_p

def graficar_grafo(nodos, nodos_p, aristas_con_pesos, aristas_con_pesos_p):
    # Crear un objeto de grafo dirigido vacío
    G = nx.DiGraph()

    # Agregar nodos al grafo
    G.add_nodes_from(nodos+nodos_p)

    # Agregar aristas con pesos al grafo
    for u, v, weight in aristas_con_pesos+aristas_con_pesos_p:
        G.add_edge(u, v, weight=weight)


    # Extraer los pesos de las aristas para usarlos en la visualización
    weights = [G[u][v]['weight'] for u, v in G.edges()]
    node_color = ['lightblue' if node not in nodos_p else 'green' for node in G.nodes()]  # Nodos diferentes colores
    edge_color = ['black' if (u, v) not in aristas_con_pesos_p else 'green' for u, v in G.edges()]  # Aristas diferentes colores


    # Graficar el grafo con los pesos en las aristas
    pos = nx.shell_layout(G)  # Algoritmo para posicionar los nodos
    nx.draw(G, pos, with_labels=True, node_color=node_color, node_size=400, font_size=10, font_weight='bold', arrows=True)
    nx.draw_networkx_edge_labels(G, pos, edge_labels={(u, v): G[u][v]['weight'] for u, v in G.edges()}, font_color='red')
    nx.draw_networkx_edges(G, pos, width=1, edge_color=edge_color, arrows=True)  # Ajustar el grosor de las aristas

    # Mostrar el grafo
    plt.show()

# Leer el grafo desde el archivo
nombre_archivo = 'graph.txt'  # Cambia esto por el nombre de tu archivo
nodos, aristas_con_pesos, nodos_p, aristas_con_pesos_p = leer_grafo_desde_archivo(nombre_archivo)


# Llamar a la función para graficar el grafo
graficar_grafo(nodos, nodos_p, aristas_con_pesos, aristas_con_pesos_p)
