import pypdf
from langchain.vectorstores import Chroma
from langchain.embeddings.openai import OpenAIEmbeddings
from langchain.document_loaders import PyPDFLoader
from langchain.text_splitter import RecursiveCharacterTextSplitter
from langchain.chat_models import ChatOpenAI
from langchain.chains import RetrievalQA

# load pdf:
loaders = [
  PyPDFLoader("data.pdf")
]
docs = []
for loader in loaders:
  docs.extend(loader.load())

# chunking text:
text_splitter = RecursiveCharacterTextSplitter(
  chunk_size = 1500, # 每个文本块的大小。这意味着每次切分文本时，会尽量使每个块包含 1500 个字符。
  chunk_overlap = 150 # 每个文本块之间的重叠部分。
)

splits = text_splitter.split_documents(docs)

persist_dir = 'docs/chroma'
embedding = OpenAIEmbeddings(
  model="BAAI/bge-m3",
  openai_api_key="sk-xxxxxx",
  openai_api_base="https://api.siliconflow.cn/v1",
  chunk_size=64 # 限制每次最多 32 条文本，安全小于 64
)

vectordb = Chroma.from_documents(
  documents=splits,
  persist_directory=persist_dir, 
  embedding_function=embedding
)

llm = ChatOpenAI(
  model='deepseek-chat',
  openai_api_key='sk-xxxxx',
  openai_api_base='https://api.deepseek.com/beta',
  temperature=0.0
)

qa_chain = RetrievalQA.from_chain_type(
  llm,
  retriever=vectordb.as_retriever()
)

# 可以以该方式进行检索问答
question = "这篇文章的主要内容是什么"
result = qa_chain({"query": question})

print(result["result"])