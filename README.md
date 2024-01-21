# Project Overview: Custom Search Engine with Inverted Index
## 1. Project Goal:

Develop a search engine that can index a large set of documents and efficiently retrieve them based on user queries. The core data structure will be an inverted index, a fundamental concept in information retrieval used by many real-world search engines.

## 2. Core Data Structures:

1. Inverted Index: A hashmap (dictionary in Python) that maps keywords to their occurrences in documents.
2. Trie: For efficient auto-completion of search queries.
3. Heap: For ranking search results.
4. Graph: If implementing a feature to find connections between documents.

## 3. Key Features:

1. Document Indexing: Read and parse documents, extracting keywords and building an inverted index.
2. Search Functionality: Allow users to search for keywords and return relevant documents.
3. Ranking Algorithm: Implement a basic ranking algorithm to order search results based on relevance.
4. Auto-Completion: Use a trie to suggest search terms as the user types.
