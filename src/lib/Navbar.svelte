<script>
    export let is_active;
</script>

<div class="tabs is-centered is-boxed">
    <ul>
        <li class={is_active == 0 ? "is-active" : ""}>
            <a href=".">Lukas Ketzer</a>
        </li>
        <li class={is_active == 1 ? "is-active" : ""}>
            <a href="./franzisco">Franzisco Schmidt</a>
        </li>
        <li class={is_active == 2 ? "is-active" : ""}>
            <a href="./ssh">SSH Guide</a>
        </li>
    </ul>
</div>

<style>
    .tabs {
        margin-bottom: 5rem;
    }
</style>
