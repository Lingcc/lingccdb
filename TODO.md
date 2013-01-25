TODO List for LingccDB
===================
Here is a list of TODO for LingccDB. And will be updated according to the develop

# Mini Demo
This directory is used for function test for little Demo as following:

 1. How CMake work
 1. How RPC works 
 1. How to write a server deamon
 1. B-Tree Index implementation
 1. Skip-List quickly in-memory code implementation
 1. How to create thread in C++ for buffer flush  in the following three ways:
    1. daemons for periodically  weekup and flush
    1. daemons for buffer full event weekup flush
    1. thread that start buffer flush work immediately, and destroied after the work done.


# Framework



# Query Interface

1. How to recieve query from the client



# Query Processor

1. How to parse the Query



# Master Server

1. How to deliver the sub-query to different servers



# Seg Server

1. How the deamon recieve the sub-Query
