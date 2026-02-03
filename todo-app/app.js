const form = document.getElementById("todo-form");
const input = document.getElementById("todo-input");
const list = document.getElementById("todo-list");
const countEl = document.getElementById("todo-count");
const filterButtons = Array.from(document.querySelectorAll(".filter"));
const clearBtn = document.getElementById("clear-completed");
const emptyState = document.getElementById("empty-state");
const emptyText = document.getElementById("empty-text");

const STORAGE_KEY = "todo_tide_items";

let todos = loadTodos();
let currentFilter = "all";

form.addEventListener("submit", (event) => {
  event.preventDefault();
  const value = input.value.trim();
  if (!value) {
    input.focus();
    return;
  }
  addTodo(value);
  input.value = "";
  input.focus();
});

clearBtn.addEventListener("click", () => {
  todos = todos.filter((todo) => !todo.completed);
  saveTodos();
  render();
});

filterButtons.forEach((button) => {
  button.addEventListener("click", () => {
    currentFilter = button.dataset.filter;
    updateFilters();
    render();
  });
});

function loadTodos() {
  try {
    const stored = JSON.parse(localStorage.getItem(STORAGE_KEY));
    return Array.isArray(stored) ? stored : [];
  } catch (error) {
    return [];
  }
}

function saveTodos() {
  localStorage.setItem(STORAGE_KEY, JSON.stringify(todos));
}

function createId() {
  if ("randomUUID" in crypto) {
    return crypto.randomUUID();
  }
  return `todo-${Date.now()}-${Math.floor(Math.random() * 10000)}`;
}

function addTodo(text) {
  const todo = {
    id: createId(),
    text,
    completed: false,
    createdAt: Date.now(),
  };
  todos.unshift(todo);
  saveTodos();
  render();
}

function toggleTodo(id) {
  todos = todos.map((todo) =>
    todo.id === id ? { ...todo, completed: !todo.completed } : todo
  );
  saveTodos();
  render();
}

function deleteTodo(id) {
  todos = todos.filter((todo) => todo.id !== id);
  saveTodos();
  render();
}

function updateFilters() {
  filterButtons.forEach((button) => {
    const isActive = button.dataset.filter === currentFilter;
    button.classList.toggle("active", isActive);
    button.setAttribute("aria-selected", isActive ? "true" : "false");
  });
}

function getFilteredTodos() {
  if (currentFilter === "active") {
    return todos.filter((todo) => !todo.completed);
  }
  if (currentFilter === "completed") {
    return todos.filter((todo) => todo.completed);
  }
  return todos;
}

function formatDate(timestamp) {
  const date = new Date(timestamp);
  return date.toLocaleString(undefined, {
    month: "short",
    day: "numeric",
    hour: "numeric",
    minute: "2-digit",
  });
}

function render() {
  const visible = getFilteredTodos();
  list.innerHTML = "";

  visible.forEach((todo) => {
    const item = document.createElement("li");
    item.className = `todo-item${todo.completed ? " completed" : ""}`;

    const check = document.createElement("button");
    check.type = "button";
    check.className = "todo-check";
    check.setAttribute("aria-pressed", todo.completed ? "true" : "false");
    check.setAttribute(
      "aria-label",
      todo.completed ? "Mark todo as active" : "Mark todo as complete"
    );
    check.addEventListener("click", () => toggleTodo(todo.id));

    const content = document.createElement("div");

    const text = document.createElement("div");
    text.className = "todo-text";
    text.textContent = todo.text;

    const meta = document.createElement("div");
    meta.className = "todo-meta";
    meta.textContent = `Added ${formatDate(todo.createdAt)}`;

    content.append(text, meta);

    const actions = document.createElement("div");
    actions.className = "todo-actions";

    const deleteBtn = document.createElement("button");
    deleteBtn.type = "button";
    deleteBtn.className = "icon-btn";
    deleteBtn.textContent = "Delete";
    deleteBtn.addEventListener("click", () => deleteTodo(todo.id));

    actions.append(deleteBtn);

    item.append(check, content, actions);
    list.append(item);
  });

  const activeCount = todos.filter((todo) => !todo.completed).length;
  countEl.textContent = activeCount.toString();
  clearBtn.disabled = !todos.some((todo) => todo.completed);

  if (visible.length === 0) {
    emptyState.hidden = false;
    emptyText.textContent =
      todos.length === 0
        ? "Nothing here yet. Add a task to get started."
        : "No tasks in this view yet.";
  } else {
    emptyState.hidden = true;
  }
}

updateFilters();
render();
