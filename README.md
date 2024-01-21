# Project Overview: Custom Search Engine with Inverted Index
## 1. Project Goal:

Develop a search engine that can index a large set of documents and efficiently retrieve them based on user queries. The core data structure will be an inverted index, a fundamental concept in information retrieval used by many real-world search engines.

## 2. Core Data Structures:

i. Inverted Index: A hashmap (dictionary in Python) that maps keywords to their occurrences in documents.
ii. Trie: For efficient auto-completion of search queries.
iii. Heap: For ranking search results.
iv. Graph: If implementing a feature to find connections between documents.

## 3. Key Features:

i. Document Indexing: Read and parse documents, extracting keywords and building an inverted index.
ii. Search Functionality: Allow users to search for keywords and return relevant documents.
iii. Ranking Algorithm: Implement a basic ranking algorithm to order search results based on relevance.
iv. Auto-Completion: Use a trie to suggest search terms as the user types.
